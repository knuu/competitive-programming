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


proc powmod[T](x: T, k: Natural, m: T): T =
  if k == 0:
    result = 1
  elif k mod 2 == 0:
    let x = powmod(x, k shr 1, m)
    result = x * x mod m
  else:
    result = powmod(x, k-1, m) * x mod m


when isMainModule:
  let
    (N, M) = input(int, 2)
    X = input(int, 1)
  var
    edges = newseq[(int, int, int)]()

  for i in 0..<M:
    let (u, v, w) = input(int, 3)
    edges.add((w, u-1, v-1))

  var (lower, equal, upper) = (0, 0, 0)

  edges.sort(cmp)

  var
    uf = initUnionFindTree(N)
    base_used = newSeqWith(M, false)
    base_min_cost = 0
  for i, e in edges:
    let (w, u, v) = e
    if not uf.hasSameRoot(u, v):
      base_min_cost += w
      base_used[i] = true
      uf.uniteNode(u, v)

  for i, used_edge in edges:
    if base_used[i]:
      continue
    uf = initUnionFindTree(N)
    uf.uniteNode(used_edge[1], used_edge[2])
    for j, edge in edges:
      let (w, u, v) = edge
      if uf.hasSameRoot(u, v) and base_used[j]:
        if used_edge[0] - w < X - base_min_cost:
          lower.inc
        elif used_edge[0] - w == X - base_min_cost:
          equal.inc
        else:
          upper.inc
        break
      uf.uniteNode(u, v)

  let
    ans1 = (powmod(2, N-1, MOD) + MOD - 2) * powmod(2, M-N+1, MOD) mod MOD
    ans2 = 2 * (powmod(2, equal, MOD) + MOD - 1) * powmod(2, upper, MOD) mod MOD
  if X < base_min_cost:
    echo(0)
  elif X == base_min_cost:
    echo((ans1 + ans2) mod MOD)
  else:
    echo(ans2)
