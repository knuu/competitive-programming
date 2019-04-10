let S = stdin.readline
var s = newSeq[int](S.len)
for i, c in S:
  s[i] = c.ord - ord('0')

var dp = newSeq[int](1 shl S.len)

var ans = 0
for state in 0..<(1 shl S.len):
  for i in 0..<S.len:
    if (state shr i and 1) == 1 or s[i] == 0:
      continue
    for j in (i+1)..<S.len:
      if (state shr j and 1) == 1 or s[i] == s[j]:
        continue
      for k in (j+1)..<S.len:
        if (state shr k and 1) == 0 and s[j] == s[k]:
          let next = state or (1 shl i) or (1 shl j) or (1 shl k)
          dp[next] = max(dp[next], dp[state] + 100 * s[i] + 10 * s[j] + s[k])
          ans = max(ans, dp[next])
ans.echo
