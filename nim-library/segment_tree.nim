import sequtils, strutils

const INF = 2147483647

type
  SegTree[T] = object
    dat: seq[T]
    size: int
    real_size: int

proc initSegTree[T](size: int): SegTree[T] =
  assert(size > 0)
  var real_size = 1
  while real_size < size: real_size = real_size shl 1
  return SegTree[T](dat: newSeqWith(2 * real_size - 1, INF), size: size, real_size: real_size)

proc update[T](segt: var Segtree[T], k: int, val: T) =
  assert(0 <= k and k < segt.size)
  var key = k + segt.real_size - 1
  segt.dat[key] = val
  while key > 0:
    key = (key - 1) div 2
    segt.dat[key] = min(segt.dat[2 * key + 1], segt.dat[2 * key + 2])

proc query[T](segt: var SegTree[T], a, b, k, left, right: int): T =
  if right <= a or b <= left: return INF
  if a <= left and right <= b: return segt.dat[k]
  let mid = (left + right) div 2
  return min(segt.query(a, b, 2 * k + 1, left, mid),
             segt.query(a, b, 2 * k + 2, mid, right))
