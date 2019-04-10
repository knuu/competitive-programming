# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

type
  SegTree[T] = object
    dat: seq[T]
    size: int
    real_size: int
    default: T

proc initSegTree[T](size: int, default = 0.int64): SegTree[T] =
  assert(size > 0)
  var real_size = 1
  while real_size < size: real_size = real_size shl 1
  return SegTree[T](dat: newSeqWith(2 * real_size - 1, default), size: size, real_size: real_size, default: default)

proc update[T](segt: var Segtree[T], k: int, val: T) =
  assert(0 <= k and k < segt.size)
  var key = k + segt.real_size - 1
  segt.dat[key] = val
  while key > 0:
    key = (key - 1) div 2
    segt.dat[key] = max(segt.dat[2 * key + 1], segt.dat[2 * key + 2])

proc query[T](segt: var SegTree[T], a, b, k, left, right: int): T =
  if right <= a or b <= left: return segt.default
  if a <= left and right <= b: return segt.dat[k]
  let mid = (left + right) div 2
  return max(segt.query(a, b, 2 * k + 1, left, mid),
             segt.query(a, b, 2 * k + 2, mid, right))

proc query[T](segt: var SegTree[T], a, b: int): T =
  return segt.query(a, b, 0, 0, segt.real_size)


when isMainModule:
  let
    tmp = getBigIntSeq
    (N, C) = (tmp[0].int, tmp[1])
  var sushi = newSeq[(int64, int64)](N)
  for i in 0..<N:
    let s = getBigIntSeq
    sushi[i] = (s[0], s[1])
  var cl, ccl = initSegTree[int64](N, 0.int64)
  var
    ans = 0.int64
    cal = 0.int64

  for i, s in sushi:
    let (x, c) = s
    cal += c
    ans = max(ans, cal - x)
    cl.update(i, cal - x)

  cal = 0.int64
  for i, s in sushi.reversed:
    let (x, c) = s
    cal += c
    ans = max(ans, cal - (C - x))
    ccl.update(i, cal - (C - x))

  cal = 0.int64
  for i, s in sushi:
    let (x, c) = s
    cal += c
    ans = max(ans, cal - 2 * x + ccl.query(0, N - i - 1))


  cal = 0.int64
  for i, s in sushi.reversed:
    let (x, c) = s
    cal += c
    ans = max(ans, cal - 2 * (C - x) + cl.query(0, N - i - 1))

  ans.echo
