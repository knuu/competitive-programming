import sequtils, strutils, algorithm, tables

type
  SegTree[T] = object
    dat: seq[T]
    size: int
    real_size: int
    default: T

proc initSegTree[T](size: int, default = 0): SegTree[T] =
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

let N = stdin.readline.parseInt
var
  boxes, width: seq[(int, int)] = @[]
  height: seq[seq[int]] = newSeqWith(1e5.int, newSeq[int](0))

for i in 0..<N:
  let
    t = stdin.readline.split.map(parseInt)
    (w, h) = (t[0], t[1])
  boxes.add((h, w))
  width.add((w, i))
  height[h-1].add(i)
width.sort(cmp)

var idx_segt = initTable[int, int]()
for i, wid in width:
  let (_, idx) = wid
  idx_segt[idx] = i
var
  dp = initSegTree[int](N)
  ans = 1

for h in countDown(1e5.int-1, 0):
  var cand: seq[(int, int)] = @[]
  for i in height[h]:
    let
      left = width.lowerBound((boxes[i][1] + 1, 0))
      val = dp.query(left, N)
    ans = max(ans, val + 1)
    cand.add((idx_segt[i], val + 1))
  for c in cand:
    let (key, val) = c
    dp.update(key, val)
ans.echo
