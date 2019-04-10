import strutils, sequtils, math

let
  tmp = stdin.readline.split.map(parseInt)
  (N, K) = (tmp[0], tmp[1])
echo(2^(N-K)-(if K == 1: N else: 0))
