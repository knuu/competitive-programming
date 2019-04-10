import strutils, sequtils, algorithm

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
  A = stdin.readline.split.map(parseInt)
var
  fwt = initFenwickTree(N, 0.int64)
  B = newSeq[(int, int)](N)
for i, a in A:
  B[i] = (a, i)
  fwt.update(i, 1.int64)
B.sort(cmp)
var ans = 0.int64
for p in B:
  let (val, idx) = p
  fwt.update(idx, -1.int64)
  ans += fwt.query(idx)
ans.echo
