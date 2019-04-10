# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc powmod[T](x, k, m: T): T =
  if k == 0:
    result = 1
  elif k mod 2 == 0:
    let x = powmod(x, k shr 1, m)
    result = x * x mod m
  else:
    result = powmod(x, k-1, m) * x mod m

proc inv[T](x: T, modulo: T = 1e9.int + 7): T =
  return powmod(x, modulo - 2, modulo)

when isMainModule:
  let
    N = getBiggestInteger
    MOD = 1e9.int64 + 7
  var fact, inv_fact = newSeq[int64](N)
  fact[0] = 1.int64
  inv_fact[0] = inv(fact[0])
  for i in 1..(N.int - 1):
    fact[i] = i.int64 * fact[i - 1] mod MOD
    inv_fact[i] = inv(fact[i])
  var ans, prev = 0.int64
  for k in ((N.int + 1) div 2)..(N.int - 1):
    let cnt = fact[k - 1] * inv_fact[k * 2 - N.int] mod MOD * fact[k] mod MOD
    ans += (cnt - prev + MOD) mod MOD * k.int64
    ans = ans mod MOD
    prev = cnt
  ans.echo
