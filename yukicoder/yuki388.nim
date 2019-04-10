import strutils, sequtils
let
  t = stdin.readline.split.map(parseInt)
  (S, F) = (t[0], t[1])
echo(S div F + 1)
