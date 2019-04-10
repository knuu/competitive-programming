import strutils, sequtils, math
let
  N = stdin.readline.parseInt
  m = 1e9.int64 + 7.int64
var
  dp = newSeqWith(N+1, newSeqWith(3, 0.int64))
dp[0][0] = 1.int64
for i in 0..<N:
  dp[i+1][0] += dp[i][1] + dp[i][2]
  dp[i+1][1] += dp[i][0]
  dp[i+1][2] += dp[i][1]
  for j in 0..2:
    dp[i+1][j] = dp[i+1][j] mod m
echo(dp[N].sum mod m)
