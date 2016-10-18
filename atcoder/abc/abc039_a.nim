import strutils, sequtils
let
  t = stdin.readline.split.map(parseInt)
  (A, B, C) = (t[0], t[1], t[2])
echo(2*(A*B+B*C+C*A))
