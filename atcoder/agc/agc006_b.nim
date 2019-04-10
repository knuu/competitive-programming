import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, x) = (tmp[0], tmp[1])
if x == 1 or x == 2 * N - 1:
  echo("No")
  quit()
echo("Yes")
let start = if x >= N: x - N else: N - 1 + x
for i in start..<(2 * N - 1):
  echo(i + 1)
for i in 0..<start:
  echo(i + 1)
