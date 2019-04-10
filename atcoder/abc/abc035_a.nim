import strutils, sequtils
let
  input = stdin.readline.split.map(parseInt)
  W = input[0]
  H = input[1]
if 4 * H == 3 * W:
  echo("4:3")
else:
  echo("16:9")
