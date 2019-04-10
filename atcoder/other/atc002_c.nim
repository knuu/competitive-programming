import strutils, sequtils
let N = stdin.readline.parseInt
var W = @[0.int64] & stdin.readline.split.map(parseBiggestInt)
for i in 0..<N: W[i+1] += W[i]
var dp = newSeqWith(N, newSeqWith(N, 1.int64 shl 62))
for i in 0..<N: dp[i][i] = 0

for width in 2..N:
  for left in 0..<N-width+1:
    let
      right = left + width - 1
      weight = W[right+1] - W[left]
    for mid in left..<right:
      dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid+1][right] + weight)
echo(dp[0][N-1])
