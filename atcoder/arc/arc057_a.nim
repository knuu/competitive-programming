import strutils, sequtils, math

let
  tmp = stdin.readline.split.map(parseBiggestInt)
  (A, K) = (tmp[0], tmp[1])
  X = 2000000000000
if K == 0:
  echo(X - A)
else:
  var
    cnt = 0
    now = A
  while now < X:
    now += 1 + K * now
    cnt.inc
  cnt.echo
