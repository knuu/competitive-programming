import strutils, sequtils

let
  N = stdin.readline.parseInt
  A = stdin.readline.split.map(parseInt)
var dp = newSeq[int](N)

for i in 0..<N-1:
  if i > 0:
    dp[i+1] = min(dp[i] + abs(A[i+1] - A[i]), dp[i-1] + abs(A[i+1] - A[i-1]))
  else:
    dp[i+1] = dp[i] + abs(A[i+1] - A[i])
dp[N-1].echo
