import strutils, sequtils

let N = stdin.readline.parseInt
var S = newSeq[int](N)

for i in 0..<N:
  S[i] = stdin.readline.parseInt

var dp = newSeqWith(10001, false)

dp[0] = true

var ans = 0
for s in S:
  for i in countdown(10000 - s, 0):
    if dp[i]:
      dp[i + s] = true
      if (i + s) mod 10 != 0:
        ans = max(ans, i + s)
ans.echo
