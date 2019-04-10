import strutils, sequtils
let
  N = stdin.readline
  L = N.len
  D = stdin.readline.parseInt
  m = (1e9.int + 7).int64
var dp = newSeqWith(L+1, newSeqWith(D+1, 0.int64))
dp[0][0] = 1.int64
for i in 0..<L:
  for d in 0..D:
    if dp[i][d] == 0.int64:
      continue
    for j in 1..7:
      if i+j > L: break
      let s = N[i..<(i+j)].parseInt
      if i+j <= L and s+d <= D:
        dp[i+j][s+d] += dp[i][d]
        dp[i+j][s+d] = dp[i+j][s+d] mod m
var ans = 0.int64
for d in dp[L]:
  ans += d
  ans = ans mod m
echo(ans)
