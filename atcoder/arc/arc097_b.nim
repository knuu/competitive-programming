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
    tmp = getIntSeq
    (N, M) = (tmp[0], tmp[1])
  var perm = getIntSeq
  var uf = initUnionFindTree(N)
  for i in 0..<M:
    let
      p = getIntSeq
      (x, y) = (p[0] - 1, p[1] - 1)
    if not uf.hasSameRoot(x, y):
      uf.uniteNode(x, y)
  var ans = 0
  for i, x in perm:
    if uf.hasSameRoot(i, x - 1):
      ans.inc
  ans.echo
