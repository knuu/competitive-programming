import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (A, B, C) = (tmp[0], tmp[1], tmp[2])
echo(if A <= C and C <= B: "Yes" else: "No")
