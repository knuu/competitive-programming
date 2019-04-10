import strutils, sequtils
let
  tmp = stdin.readline.split.map(parseBiggestInt)
  (N, M, P) = (tmp[0], tmp[1], tmp[2])
proc powmod[T](x, k, m: T): T =
  if k == 0:
    result = 1
  elif k mod 2 == 0:
    let x = powmod(x, k shr 1, m)
    result = x * x mod m
  else:
    result = powmod(x, k-1, m) * x mod m
echo(powmod(N, P, M))
