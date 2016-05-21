import strutils, sequtils
let
  input = stdin.readline.split.map(parseInt)
  (A, B) = (input[0], input[1])
if B mod A == 0:
  echo(B div A)
else:
  echo(B div A + 1)
