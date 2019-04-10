let
  S = stdin.readline
  N = S.len
var ans = N

for i in 0..<(N-1):
  if S[i] == 'S' and S[i+1] == 'T':
    var (left, right) = (i, i+1)
    while left >= 0 and right < N and S[left] == 'S' and S[right] == 'T':
      ans -= 2
      left.dec
      right.inc
ans.echo
