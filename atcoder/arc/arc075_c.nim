import sequtils, strutils, algorithm

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
  tmp = stdin.readline.split.map(parseInt)
  (N, K) = (tmp[0], tmp[1].int64)
var A = newSeq[int64](N)

for i in 0..<N:
  A[i] = stdin.readline.parseBiggestInt

var acc = newSeq[(int64, int)](N + 1)

acc[0] = (0.int64, 0)

for i in 0..<N:
  acc[i + 1] = (acc[i][0] + A[i], i + 1)
for i, p in acc:
  let (v, k) = p
  acc[i] = (v - i.int64 * K, k)

acc.sort(cmp)

var acc_index = newSeq[int](N + 1)

for i, p in acc:
  let (v, k) = p
  acc_index[k] = i

var
  ans = 0.int64
  fwt = initFenwickTree[int64](N + 1, 0)

for i in countdown(N, 0):
  ans += fwt.query(acc_index[i], N + 1)
  fwt.update(acc_index[i], 1.int64)

ans.echo
