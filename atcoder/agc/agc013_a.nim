import strutils, sequtils

let
  N = stdin.readline.parseInt
  A = stdin.readline.split.map(parseInt)
var dp = newSeqWith(N, newSeqWith(2, 0))
dp[0][0] = 1
dp[0][1] = 1

for i in 0..<(N-1):
  dp[i + 1][0] = min(dp[i][0], dp[i][1]) + 1
  dp[i + 1][1] = min(dp[i][0], dp[i][1]) + 1
  if A[i] <= A[i + 1]:
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0])
  if A[i] >= A[i + 1]:
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1])
dp[N-1].min.echo
