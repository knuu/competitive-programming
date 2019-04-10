import strutils, sequtils

let
  S = stdin.readline
  N = S.len
var ans = 0
for i, s in S:
  if s == 'U':
    ans += (N - 1) - i + 2 * i
  else:
    ans += i + 2 * ((N - 1) - i)
ans.echo
