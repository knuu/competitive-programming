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
  heapq: seq[(int64, int)] = @[]
  dist, rev_dist = newSeqWith(N, 1e18.int64)

dist[0] = 0.int64
rev_dist[0] = 0.int64

heapq.add((0.int64, 0))
while heapq.len > 0:
  let (d, v) = heapq[0]
  heapq[0] = heapq[^1]
  heapq.setlen(heapq.len-1)
  var par = 0
  while par < heapq.len:
    let (left, right) = (2*par+1, 2*par+2)
    if right < heapq.len:
      if heapq[par] <= min(heapq[left], heapq[right]):
        break
      elif heapq[left] < heapq[right]:
        swap(heapq[par], heapq[left])
        par = left
      else:
        swap(heapq[par], heapq[right])
        par = right
    elif left < heapq.len:
      if heapq[left] < heapq[par]:
        swap(heapq[par], heapq[left])
        par = left
      else:
        break
    else:
      break

  if d > dist[v]:
    continue
  for e in edge[v]:
    let (to, cost) = e
    if dist[to] > d + cost:
      dist[to] = d + cost
      heapq.add((dist[to], to))
      var i = heapq.len-1
      while i > 0:
        let par = (i-1) div 2
        if heapq[i] < heapq[par]:
          swap(heapq[i], heapq[par])
        i = par

heapq = @[(0.int64, 0)]
while heapq.len > 0:
  let (d, v) = heapq[0]
  heapq[0] = heapq[^1]
  heapq.setlen(heapq.len-1)
  var par = 0
  while par < heapq.len:
    let (left, right) = (2*par+1, 2*par+2)
    if right < heapq.len:
      if heapq[par] <= min(heapq[left], heapq[right]):
        break
      elif heapq[left] < heapq[right]:
        swap(heapq[par], heapq[left])
        par = left
      else:
        swap(heapq[par], heapq[right])
        par = right
    elif left < heapq.len:
      if heapq[left] < heapq[par]:
        swap(heapq[par], heapq[left])
      break
    else:
      break

  var i = heapq.len - 1
  while i > 0:
    let par = (i-1) div 2
    if heapq[i] < heapq[par]:
      swap(heapq[i], heapq[par])
    i = par
  if d > rev_dist[v]:
    continue
  for e in rev_edge[v]:
    let (to, cost) = e
    if rev_dist[to] > d + cost:
      rev_dist[to] = d + cost
      heapq.add((rev_dist[to], to))
      var i = heapq.len-1
      while i > 0:
        let par = (i-1) div 2
        if heapq[i] < heapq[par]:
          swap(heapq[i], heapq[par])
        i = par
var ans = 0.int64
for i in 0..<N:
  ans = max(ans, A[i] * max(0.int64, T - dist[i] - rev_dist[i]))
echo(ans)
