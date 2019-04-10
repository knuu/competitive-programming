import sequtils, strutils, math

let
  input = stdin.readline.split.map(parseInt)
  (N, K) = (input[0], input[1])

var dp = newSeqWith(N, newSeqWith(K, 0))
for i in 0..<K:
  dp[0][i] = 1
for i in 0..<(N-1):
  let sumdp = dp[i].sum
  for j in 0..<K:
    dp[i+1][j] += sumdp - dp[i][j]
dp[^1].sum.echo
