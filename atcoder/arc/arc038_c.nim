import strutils, sequtils

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
  return SegTree[T](dat: newSeqWith(2 * real_size - 1, -1), size: size, real_size: real_size)

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

proc query[T](segt: var SegTree[T], a, b: int): T =
  return segt.query(a, b, 0, 0, segt.real_size)

let N = stdin.readline.parseInt
var cup = newSeq[(int, int)](N - 1)
for i in 0..<(N-1):
  let tmp = stdin.readline.split.map(parseInt)
  cup[i] = (tmp[0], tmp[1])

var grundy = newSeq[int](N)
grundy[0] = 0

var segt = initSegTree[int](N)
segt.update(0, 0)

for i in 0..<(N-1):
  var (left, right) = (0, cup[i][0] + 1)
  while left + 1 < right:
    let mid = (left + right) div 2
    if segt.query(0, mid) < (i + 1) - cup[i][0]:
      right = mid
    else:
      left = mid
  grundy[i + 1] = left
  segt.update(left, i + 1)

var state = 0
for i in 0..<(N-1):
  if cup[i][1] %% 2 == 1:
    state = state xor grundy[i + 1]
echo(if state > 0: "First" else: "Second")
