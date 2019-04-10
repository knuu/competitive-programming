import strutils, sequtils, algorithm, math

let
  t = stdin.readline.split.map(parseInt)
  (N, X) = (t[0], t[1])
echo(min(X-1, N-X))
