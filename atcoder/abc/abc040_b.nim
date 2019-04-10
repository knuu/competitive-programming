import strutils, math

let N = stdin.readline.parseInt
var ans = N-1

for w in 1..sqrt(N.float).int:
  let h = N div w
  assert(h >= w)
  ans = min(ans, N - w * h + (h - w))
ans.echo
