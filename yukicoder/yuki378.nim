import strutils
let N = stdin.readline.parseBiggestInt
var
  now = N
  total = 0.int64
while now > 0:
  total += now
  now = now div 2
echo(2 * N - total)
