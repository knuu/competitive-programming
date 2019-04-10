# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

type
  UnionFind = object
    parent, rank, count: seq[int]

proc initUnionFindTree(size: int): UnionFind =
  assert(size > 0)
  return UnionFind(parent: newSeqWith(size, -1), rank: newSeqWith(size, 0), count: newSeqWith(size, 1))

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
    uf.count[y] += uf.count[x]
  else:
    uf.parent[y] = x
    if (uf.rank[x] == uf.rank[y]): uf.rank[x].inc
    uf.count[x] += uf.count[y]

proc hasSameRoot(uf: var UnionFind, x, y: int): bool =
  return uf.findRoot(x) == uf.findRoot(y)

proc countNode(uf: var UnionFind, x: int): int =
  return uf.count[uf.findRoot(x)]

when isMainModule:
  let
    tmp = getIntSeq
    (N, M) = (tmp[0], tmp[1])
  var edges = newSeq[(int, int)](M)
  for i in 0..<M:
    let e = getIntSeq.mapIt(it - 1)
    edges[i] = (e[0], e[1])
  let Q = getInteger
  var queries = newSeq[(int, int, int)](Q)
  for i in 0..<Q:
    let p = getIntSeq.mapIt(it - 1)
    queries[i] = (p[0], p[1], p[2] + 1)

  var intervals = newSeqWith(Q, (0, M))
  for _ in 0..log2(M.float).int:
    var mids = newSeq[int](Q)
    for i, interval in intervals:
      let (left, right) = interval
      mids[i] = (left + right) shr 1
    var dict = initTable[int, seq[int]]()
    for i, mid in mids:
      dict.mgetOrPut(mid, newSeq[int]()).add(i)
    var uf = initUnionFindTree(N)
    for i, edge in edges:
      let (a, b) = edge
      uf.uniteNode(a, b)
      for idx in dict.getOrDefault(i + 1):
        let
          (x, y, z) = queries[idx]
          (left, right) = intervals[idx]
        if (uf.hasSameRoot(x, y) and uf.countNode(x) >= z) or (not uf.hasSameRoot(x, y) and uf.countNode(x) + uf.countNode(y) >= z):
          intervals[idx] = (left, mids[idx])
        else:
          intervals[idx] = (mids[idx], right)
  for interval in intervals:
    interval[1].echo
