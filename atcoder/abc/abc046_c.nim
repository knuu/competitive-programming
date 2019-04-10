import strutils, sequtils, math
let
  input = stdin.readline.split.map(parseFloat)
  (xs, ys, xt, yt) = (input[0], input[1], input[2], input[3])
  N = stdin.readline.parseInt
var points = newSeq[seq[float]](N)

for i in 0..<N:
  points[i] = stdin.readline.split.map(parseFloat)

let
  start = N
  goal = N + 1

var Adj = newSeqWith(N + 2, newSeqWith(N + 2, 0.0))
for i in 0..<N:
  for j in (i+1)..<N:
    let d = hypot(points[i][0] - points[j][0], points[i][1] - points[j][1])
    Adj[i][j] = Adj[j][i] = max(0.0, d - points[i][2] - points[j][2])

for i in 0..<N:
  Adj[start][i] = Adj[i][start] = max(0.0, hypot(points[i][0] - xs, points[i][1] - ys) - points[i][2])
  Adj[goal][i] = Adj[i][goal] = max(0.0, hypot(points[i][0] - xt, points[i][1] - yt) - points[i][2])
Adj[start][goal] = Adj[goal][start] = hypot(xs - xt, ys - yt)

var dist = newSeqWith(N + 2, 1e18)
dist[start] = 0
for i in 0..<(N+2):
  for j in 0..<(N+2):
    dist[i]
