# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

type
  UnionFind = object
    parent, rank: seq[int]

proc initUnionFindTree(size: int): UnionFind =
  assert(size > 0)
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
    N = getInteger
  var
    X, Y = newSeq[(int, int)](N)
  for i in 0..<N:
    let tmp = getIntSeq
    X[i] = (tmp[0], i)
    Y[i] = (tmp[1], i)
  X.sort(cmp)
  Y.sort(cmp)
  var diff = newSeq[(int, int, int)]()
  for i in 1..<N:
    diff.add((X[i][0] - X[i - 1][0], X[i][1], X[i - 1][1]))
  for i in 1..<N:
    diff.add((Y[i][0] - Y[i - 1][0], Y[i][1], Y[i - 1][1]))
  diff.sort(cmp)

  var
    ans = 0.int64
    uft = initUnionFindTree(N)
  for edge in diff:
    let (cost, x, y) = edge
    if not uft.hasSameRoot(x, y):
      ans += cost.int64
      uft.uniteNode(x, y)
  ans.echo
