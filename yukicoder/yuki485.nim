import strutils, sequtils, strscans

var A, B: int
let input = stdin.readline
discard input.scanf("$i $i", A, B)

if B mod A == 0:
  echo(B div A)
else:
  echo("NO")
