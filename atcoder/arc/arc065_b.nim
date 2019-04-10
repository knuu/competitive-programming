import strutils, sequtils, tables

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

let
  input = stdin.readline.split.map(parseInt)
  (N, K, L) = (input[0], input[1], input[2])
var
  road = initUnionFindTree(N)
  rail = initUnionFindTree(N)

for _ in 0..<K:
  let e = stdin.readline.split.mapIt(it.parseInt-1)
  road.uniteNode(e[0], e[1])
for _ in 0..<L:
  let e = stdin.readline.split.mapIt(it.parseInt-1)
  rail.uniteNode(e[0], e[1])
var T = initTable[(int, int), int]()
for i in 0..<N:
  var p = (road.findRoot(i), rail.findRoot(i))
  T[p] = T.getOrDefault(p) + 1
var ans = newSeq[int](N)
for i in 0..<N: ans[i] = T[(road.findRoot(i), rail.findRoot(i))]
ans.mapIt(it.intToStr).join(" ").echo
