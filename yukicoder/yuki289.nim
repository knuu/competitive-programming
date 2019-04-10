import strutils
let S = stdin.readline
var ans = 0
for c in S:
  if c.isDigit:
    ans += c.ord - '0'.ord
echo(ans)
