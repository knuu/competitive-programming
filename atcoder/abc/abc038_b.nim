import strutils, sequtils
let
  A = stdin.readline.split.map(parseInt)
  B = stdin.readline.split.map(parseInt)
var flag = false

for a in A:
  for b in B:
    if a == b:
      echo("YES")
      quit(0)
echo("NO")
