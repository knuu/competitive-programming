import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, K) = (tmp[0], tmp[1])
  H = stdin.readline.split.map(parseInt)
var
  cnt = K
  ans, left = 0
for right in 0..<N:
  if H[right] == 0:
    cnt.dec
  while cnt < 0:
    if H[left] == 0:
      cnt.inc
    left.inc
  ans = max(ans, right - left + 1)
ans.echo
