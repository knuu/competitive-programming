import sequtils, strutils, math

proc powmod[T](x, k, m: T): T =
  if k == 0:
    result = 1
  elif k mod 2 == 0:
    let x = powmod(x, k shr 1, m)
    result = x * x mod m
  else:
    result = powmod(x, k-1, m) * x mod m

let
  m = 1000003.int64
  t = stdin.readline.split.map(parseBiggestInt)
  (x, N) = (t[0], t[1])
echo(stdin.readline.split.mapIt(x.powmod(it.parseBiggestInt, m.int64)).sum mod m)
