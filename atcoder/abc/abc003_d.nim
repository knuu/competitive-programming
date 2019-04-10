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

proc popcount[T: int64|int](a: T): cint {. importc: "__builtin_popcountl", nodecl, nosideeffect.}

proc comb(n, k: int, modulo: int64, fact, inv_fact: seq[int64]): int64 =
  if n < 0 or k < 0 or n < k:
    return 0
  return fact[n] * inv_fact[k] mod modulo * inv_fact[n - k] mod modulo

when isMainModule:
  let
    modulo = 1e9.int64 + 7.int64
    tmp = getIntSeq
    (R, C) = (tmp[0], tmp[1])
    tmp2 = getIntSeq
    (X, Y) = (tmp2[0], tmp2[1])
    tmp3 = getIntSeq
    (D, L) = (tmp3[0], tmp3[1])
  var fact, inv_fact = newSeq[int64](X * Y + 1)
  fact[0] = 1
  inv_fact[0] = inv(1)
  var fact_i = 1.int64
  for i in 1..(X * Y).int:
    fact_i = (fact_i * i.int64) mod modulo
    fact[i] = fact_i
    inv_fact[i] = inv(fact_i, modulo)

  var ans = 0.int64
  for state in 0..<(1 shl 4):
    let
      x = X - (state shr 0 and 1) - (state shr 1 and 1)
      y = Y - (state shr 2 and 1) - (state shr 3 and 1)
    if x < 0 or y < 0:
      continue
    var cc = comb(x * y, D, modulo, fact, inv_fact) * comb(x * y - D, L, modulo, fact, inv_fact) mod modulo
    if state.popcount mod 2 == 0:
      ans = (ans + cc) mod modulo
    else:
      ans = (ans - cc + modulo) mod modulo
  echo(ans * (R - X + 1) mod modulo * (C - Y + 1) mod modulo)
