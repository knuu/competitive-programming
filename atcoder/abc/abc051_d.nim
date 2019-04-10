import strutils, sequtils, sets

let
  t = stdin.readline.split.map(parseInt)
  (N, M) = (t[0], t[1])
var edge = newSeq[(int, int, int)]()

for _ in 0..<M:
  let e = stdin.readline.split.mapIt(it.parseInt-1)
  edge.add((e[0], e[1], e[2] + 1))
  edge.add((e[1], e[0], e[2] + 1))

var used = initSet[(int, int)]()

for root in 0..<N:
  var
    dist = newSeqWith(N, 1e6.int)
    prev = newSeqWith(N, -1)
  dist[root] = 0
  while true:
    var update = false
    for e in edge:
      let (v, u, c) = e
      if dist[v] + c < dist[u]:
        dist[u] = dist[v] + c
        prev[u] = v
        update = true
    if not update:
      break
  for i in 0..<N:
    var now = i
    while now != -1:
      if prev[now] != -1:
        used.incl(if prev[now] < now: (prev[now], now) else: (now, prev[now]))
      now = prev[now]
echo(M - used.len)
