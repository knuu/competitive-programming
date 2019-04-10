import sequtils, strutils

type
  FenwickTree[T] = object
    dat: seq[T]
    size: int
    initial: T

proc initFenwickTree[T](size: int, initial: T): FenwickTree[T] =
  assert(size > 0)
  return FenwickTree[T](dat: newSeqWith(size, initial), size: size, initial: initial)

proc update[T](fwt: var FenwickTree[T], k: int, val: T) =
  assert(0 <= k and k < fwt.size)
  var key = k
  while key < fwt.size:
    fwt.dat[key] += val
    key = key or (key + 1)

proc query[T](fwt: var FenwickTree[T], k: int): T =
  assert(k >= 0)
  var key = k - 1
  result = fwt.initial
  while key >= 0:
    result += fwt.dat[key]
    key = (key and (key + 1)) - 1

proc query[T](fwt: var FenwickTree[T], left, right: int): T =
  assert(0 <= left and left <= right and right <= fwt.size)
  return fwt.query(right) - fwt.query(left)

proc index[T](fwt: var FenwickTree[T], k: int): T =
  assert(0 <= k and k < fwt.size)
  return fwt.query(k + 1) - fwt.index(k)

let
  N = stdin.readline.parseInt
  A = stdin.readline.split.mapIt(it.parseInt-1)
  MOD = 1e9.int64 + 7
var
  fwt = initFenwickTree[int64](N, 0.int64)
  fact = @[1.int64]
for i in 0..<N:
  fwt.update(i, 1)
  fact.add(fact[^1] * (i + 1).int64 mod MOD)

var ans = 1.int64
for i in 0..<N:
  fwt.update(A[i], -1.int64)
  ans += fact[N - (i + 1)] * fwt.query(A[i])
  ans = ans %% MOD
ans.echo
