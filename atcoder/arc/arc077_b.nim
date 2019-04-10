# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

let MOD = 1e9.int64 + 7
var
  fact = newSeq[int64]()
  inv_fact = newSeq[int64]()

proc powmod[T](x, k, m: T): T =
  if k == 0:
    result = 1
  elif k mod 2 == 0:
    let x = powmod(x, k shr 1, m)
    result = x * x mod m
  else:
    result = powmod(x, k-1, m) * x mod m


proc inv(x: int64): int64 =
  return powmod(x, MOD - 2, MOD)

proc nCk(n, k: int): int64 =
  if k < 0 or n < k:
    return 0
  else:
    return fact[n] * inv_fact[k] mod MOD * inv_fact[n - k] mod MOD

when isMainModule:
  let
    N = getInteger
    A = getIntSeq
  var counter = newSeq[int](N + 1)
  for a in A:
    counter[a].inc
  var two = 0
  for i, c in counter:
    if c == 2:
      two = i
  var idxes = newSeq[int]()
  for i, a in A:
    if a.int == two:
      idxes.add(i)
  assert(idxes.len == 2)


  fact.add(1)
  inv_fact.add(inv(1))
  for i in 1..N:
    fact.add(fact[^1] * i.int64 mod MOD)
    inv_fact.add(inv(fact[^1]))


  for i in 1..(N + 1):
    var ans = 0.int64
    echo((nCk(N - 1, i) + 2 * nCk(N - 1, i - 1) + MOD - nCk(N + idxes[0] - idxes[1], i - 1) + nCk(N - 1, i - 2)) mod MOD)
