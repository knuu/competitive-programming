import algorithm, complex, future, macros, math, queues, rationals, sets, sequtils, strutils, tables # for 0.13.0
# import algorithm, bitops, complex, deques, heapqueue, lenientops, macros, math, queues, rationals, sets, sequtils, strformat, strscans, strutils, sugar, tables # for 0.19

# ----- input macro by nimon -----

macro unpack*(input: seq; count: static[int]): untyped =
  result = quote do: ()
  when NimMinor <= 13:
    for i in 0..<count: result[0].add quote do: `input`[`i`]
  else:
    for i in 0..<count: result.add quote do: `input`[`i`]

## count == 0 のとき unpackしない(seq)
## count >  0 のとき count個分 unpack した結果の tuple を返す
type UnselectableTypeError = object of Exception
template input*(typ: typedesc; count: Natural = 0): untyped =
  let line = stdin.readLine.split
  when count == 0:
    when typ is int:    line.map(parseInt)
    elif typ is float:  line.map(parseFloat)
    elif typ is string: line
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")
  else:
    when typ is int:    line.map(parseInt).unpack(count)
    elif typ is float:  line.map(parseFloat).unpack(count)
    elif typ is string: line.unpack(count)
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")

# 2-dim table
template inputs*(typ: typedesc; count = 0; rows = 1): untyped =
  (1..rows).mapIt(input(typ, count))

# ----- end input macro -----

# from https://nim-lang.org/docs/manual.html#macros-expression-macros
# when NimMinor >= 16, you can use future.dump (sugar.dump)
macro debug(args: varargs[untyped]): untyped =
  result = nnkStmtList.newTree()
  for n in args:
    result.add newCall("write", newIdentNode("stderr"), newLit(n.repr))
    result.add newCall("write", newIdentNode("stderr"), newLit(": "))
    result.add newCall("write", newIdentNode("stderr"), n)
    result.add newCall("writeLine", newIdentNode("stderr"), newLit(""))

const MOD = 10^9 + 7
const INF = high(int)

proc rec(left, right, D: int, A: seq[int], edge: var seq[(int, int, int)]) =
  if right - left <= 1:
    return
  let mid = (left + right) div 2
  var
    l_min = INF
    l_idx = -1
  for i in left..<mid:
    if A[i] - i * D < l_min:
      l_min = A[i] - i * D
      l_idx = i
  var
    r_min = INF
    r_idx = -1
  for i in mid..<right:
    if A[i] + i * D < r_min:
      r_min = A[i] + i * D
      r_idx = i
  for i in left..<mid:
    edge.add((A[i] + A[r_idx] + D * (r_idx - i), i, r_idx))
  for i in mid..<right:
    edge.add((A[i] + A[l_idx] + D * (i - l_idx), l_idx, i))

  rec(left, mid, D, A, edge)
  rec(mid, right, D, A, edge)

type
  UnionFind = object
    parent, rank: seq[int]

proc initUnionFindTree(size: Natural): UnionFind =
  return UnionFind(parent: newSeqWith(size, -1), rank: newSeqWith(size, 0))

proc findRoot(uf: var UnionFind, x: int): int =
  if uf.parent[x] == -1:
    return x
  else:
    uf.parent[x] = uf.findRoot(uf.parent[x])
    return uf.parent[x]

proc uniteNode(uf: var UnionFind, x, y: int) =
  let
    x = uf.findRoot(x)
    y = uf.findRoot(y)
  if x == y:
    return
  elif uf.rank[x] < uf.rank[y]:
    uf.parent[x] = y
  else:
    uf.parent[y] = x
    if (uf.rank[x] == uf.rank[y]): uf.rank[x].inc

proc hasSameRoot(uf: var UnionFind, x, y: int): bool =
  return uf.findRoot(x) == uf.findRoot(y)


when isMainModule:
  let
    (N, D) = input(int, 2)
    A = input(int)

  var edge = newSeq[(int, int, int)]()
  rec(0, N, D, A, edge)

  edge.sort(cmp)

  var
    dset = initUnionFindTree(N)
    mincost = 0
  for e in edge:
    let (cost, v, w) = e
    if dset.hasSameRoot(v, w):
      continue
    dset.uniteNode(v, w)
    mincost += cost
  mincost.echo
