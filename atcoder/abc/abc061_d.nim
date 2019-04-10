import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, M) = (tmp[0], tmp[1])
var edge = newSeq[(int, int, int64)](M)

for i in 0..<M:
  let tmp = stdin.readline.split.map(parseInt)
  edge[i] = (tmp[0]-1, tmp[1]-1, -tmp[2].int64)

let INF = 1e17.int64
var dp = newSeqWith(N, INF)
dp[0] = 0


for i in 0..<N:
  var flag = false
  for e in edge:
    let (a, b, c) = e
    if dp[a] < INF and dp[a] + c < dp[b]:
      if i == N - 1 and b == N - 1:
        echo("inf")
        quit()
      dp[b] = dp[a] + c
      flag = true
  if not flag:
    break
echo(-dp[N-1])
