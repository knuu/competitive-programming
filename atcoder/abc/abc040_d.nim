import strutils, sequtils, algorithm

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
  t = stdin.readline.split.map(parseInt)
  (N, M) = (t[0], t[1])
var query = newSeq[(int, int, int)]()

for _ in 0..<M:
  let
    t1 = stdin.readline.split.map(parseInt)
    (a, b, c) = (t1[0]-1, t1[1]-1, t1[2])
  query.add((-c, a, b))

let Q = stdin.readline.parseInt

for i in 0..<Q:
  let
    t2 = stdin.readline.split.map(parseInt)
    (v, w) = (t2[0]-1, t2[1])
  query.add((-w, -i-1, v))

query.sort(cmp)

var
  uf = initUnionFindTree(N)
  child = newSeqWith(N, 1)
  ans = newSeq[int](Q)

for q in query:
  let (year, a, b) = q
  if a < 0:
    ans[-a-1] = child[uf.findRoot(b)]
  else:
    let
      ra = uf.findRoot(a)
      rb = uf.findRoot(b)
    if ra == rb:
      continue
    uf.uniteNode(ra, rb)
    if uf.findRoot(ra) == rb:
      child[rb] += child[ra]
    elif uf.findRoot(rb) == ra:
      child[ra] += child[rb]
ans.mapIt(it.intToStr).join("\n").echo
