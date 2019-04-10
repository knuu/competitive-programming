import sequtils
var
  S = stdin.readline
  count_w = newSeqWith(S.len+1, 0.int64)
for i in countdown(S.len-1, 0):
  count_w[i] = count_w[i+1]
  if S[i] == 'w': count_w[i].inc
var ans = 0.int64
for i, cnt in pairs(count_w):
  if S[i] == 'c':
    ans += count_w[i] * (count_w[i] - 1.int64) div 2.int64
echo(ans)
