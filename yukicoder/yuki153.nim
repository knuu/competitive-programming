import strutils, sequtils, math
let N = stdin.readline.parseInt
var dp = newSeqWith(2, newSeqWith(32768, 0))
dp[0][0] = 1
for i, a in stdin.readline.split.map(parseInt):
  let
    c = i and 1
    n = c xor 1
  for i in 0..<32768:
    if dp[c][i] == 1:
      dp[n][i xor a] = 1
      dp[n][i] = 1
dp[N and 1].sum.echo
