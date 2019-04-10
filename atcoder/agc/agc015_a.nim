import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseBiggestInt)
  (N, A, B) = (tmp[0], tmp[1], tmp[2])
if A > B or (N == 1 and A != B):
  echo(0)
else:
  echo(B * (N - 1.int64) + A - A * (N - 1.int64) - B + 1.int64)
