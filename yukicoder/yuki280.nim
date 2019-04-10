let
  S = stdin.readline
  N = S.len
var ans = 0
for i in 0..<N:
  var l, r = i
  while l >= 0 and r < N and S[l] == S[r] and r - l + 1 < N:
    ans = ans.max(r - l + 1)
    l.dec
    r.inc
  l = i
  r = i + 1
  while l >= 0 and r < N and S[l] == S[r] and r - l + 1 < N:
    ans = ans.max(r - l + 1)
    l.dec
    r.inc
ans.echo
