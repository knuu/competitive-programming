import strutils, sequtils
let
  t = stdin.readline.split.map(parseBiggestInt)
  (A, B, C, D) = (t[0], t[1], t[2], t[3])
echo(A * B mod D * C mod D)
