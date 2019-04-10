import strutils, algorithm, math, sequtils
let S = stdin.readline
var s = newSeq[int](S.len)
for i, c in S:
  s[i] = c.ord - ord('0')

var dp = newSeqWith(1 shl S.len, -1)

proc dfs(state: int): int =
  if dp[state] != -1:
    return dp[state]
  result = 0
  for i in 0..<S.len:
    if (state shr i and 1) == 1 or s[i] == 0:
      continue
    for j in (i+1)..<S.len:
      if (state shr j and 1) == 1 or s[i] == s[j]:
        continue
      for k in (j+1)..<S.len:
        if (state shr k and 1) == 0 and s[j] == s[k]:
          result = max(result, dfs(state or (1 shl i) or (1 shl j) or (1 shl k)) + 100 * s[i] + 10 * s[j] + s[k])
  dp[state] = result
dfs(0).echo
