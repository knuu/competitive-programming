type
  Heap*[T]= object
    data*: seq[T]
    size*: int
    comp: proc (x: T, y: T): int
  EmptyHeapError* = object of Exception

proc siftup[T](h: var Heap[T]) =
  var i = h.size - 1
  while i > 0:
    var par = (i-1) div 2
    if h.comp(h.data[par], h.data[i]) > 0:
      swap(h.data[i], h.data[par])
      i = par
    else:
      break
proc siftdown[T](h: var Heap[T]) =
  var par = 0
  while par < h.size:
    let (left, right) = (2*par+1, 2*par+2)
    if right < h.size:
      if h.comp(h.data[par], min(h.data[left], h.data[right])) <= 0:
        break
      elif h.comp(h.data[left], h.data[right]) < 0:
        swap(h.data[par], h.data[left])
        par = left
      else:
        swap(h.data[par], h.data[right])
        par = right
    elif left < h.size:
      if h.comp(h.data[left], h.data[par]) < 0:
        swap(h.data[par], h.data[left])
        par = left
      else:
        break
    else:
      break
proc newHeap*[T](comparator: proc (x: T, y: T): int = cmp): Heap[T] =
  Heap[T](data: newSeq[T](), size: 0, comp: comparator)
proc push*[T](h: var Heap[T], x: T) =
  h.data.add(x)
  h.size.inc
  h.siftup
proc pop*[T](h: var Heap[T]): T =
  if h.size <= 0:
    raise newException(EmptyHeapError, "cannot pop element, heap is empty")
  result = h.data[0]
  h.data[0] = h.data[^1]
  h.size.dec
  h.data.setlen(h.size)
  h.siftdown
proc empty*[T](h: var Heap[T]): bool {. inline .} = h.data.len == 0

import strutils, sequtils, algorithm
let
  input = stdin.readline.split.map(parseInt)
  N = input[0]
  M = input[1]
  T = input[2].int64
  A = stdin.readline.split.map(parseBiggestInt)
var edge, rev_edge: seq[seq[(int, int64)]] = newSeqWith(N, newSeq[(int, int64)](0))
for _ in 0..<M:
  let e = stdin.readline.split.map(parseInt)
  edge[e[0]-1].add((e[1]-1, e[2].int64))
  rev_edge[e[1]-1].add((e[0]-1, e[2].int64))
var
  heapq = newHeap[(int64, int)]()
  dist, rev_dist = newSeqWith(N, 1e18.int64)

dist[0] = 0.int64
rev_dist[0] = 0.int64

heapq.push((0.int64, 0))
while not heapq.empty:
  let (d, v) = heapq.pop()
  if d > dist[v]:
    continue
  for e in edge[v]:
    let (to, cost) = e
    if dist[to] > d + cost:
      dist[to] = d + cost
      heapq.push((dist[to], to))

heapq.push((0.int64, 0))
while not heapq.empty:
  let (d, v) = heapq.pop()
  if d > rev_dist[v]:
    continue
  for e in rev_edge[v]:
    let (to, cost) = e
    if rev_dist[to] > d + cost:
      rev_dist[to] = d + cost
      heapq.push((rev_dist[to], to))

var ans = 0.int64
for i in 0..<N:
  ans = max(ans, A[i] * max(0.int64, T - dist[i] - rev_dist[i]))
echo(ans)
