import strutils, sequtils
let
  input = stdin.readline.split.map(parseInt)
  (N, K) = (input[0], input[1])
if N == K:
  echo("Drew")
elif (N + 1) mod 3 == K:
  echo("Won")
else:
  echo("Lost")
