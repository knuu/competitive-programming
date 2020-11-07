import algorithm, complex, future, macros, math, queues, rationals, sets, sequtils, strutils, tables # for 0.13.0
# import algorithm, bitops, complex, deques, heapqueue, lenientops, macros, math, queues, rationals, sets, sequtils, strformat, strscans, strutils, sugar, tables # for 0.19

# ----- input macro by nimon -----

macro unpack*(input: seq; count: static[int]): untyped =
  result = quote do: ()
  when NimMinor <= 13:
    for i in 0..<count: result[0].add quote do: `input`[`i`]
  else:
    for i in 0..<count: result.add quote do: `input`[`i`]

## count == 0 のとき unpackしない(seq)
## count >  0 のとき count個分 unpack した結果の tuple を返す
type UnselectableTypeError = object of Exception
template input*(typ: typedesc; count: Natural = 0): untyped =
  let line = stdin.readLine.split
  when count == 0:
    when typ is int:    line.map(parseInt)
    elif typ is float:  line.map(parseFloat)
    elif typ is string: line
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")
  else:
    when typ is int:    line.map(parseInt).unpack(count)
    elif typ is float:  line.map(parseFloat).unpack(count)
    elif typ is string: line.unpack(count)
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")

# 2-dim table
template inputs*(typ: typedesc; count = 0; rows = 1): untyped =
  (1..rows).mapIt(input(typ, count))

# ----- end input macro -----

# from https://nim-lang.org/docs/manual.html#macros-expression-macros
# when NimMinor >= 16, you can use future.dump (sugar.dump)
macro debug(args: varargs[untyped]): untyped =
  result = nnkStmtList.newTree()
  for n in args:
    result.add newCall("write", newIdentNode("stderr"), newLit(n.repr))
    result.add newCall("write", newIdentNode("stderr"), newLit(": "))
    result.add newCall("write", newIdentNode("stderr"), n)
    result.add newCall("writeLine", newIdentNode("stderr"), newLit(""))

const MOD = 10^9 + 7
const INF = high(int)

type
  SegTree[T] = object
    dat: seq[T]
    size: Natural
    real_size: Natural
    merge: proc (x, y: T): T
    default: T

proc max_merge[T](x, y: T): T =
  result = if x > y: x else: y

proc min_merge[T](x, y: T): T =
  result = if x > y: y else: x

proc sum_merge[T](x, y: T): T = x + y

proc initSegTree[T](size: Natural, merge: proc (x, y: T): T = max_merge, default = 0): SegTree[T] =
  var real_size = 1
  while real_size < size: real_size = real_size shl 1
  return SegTree[T](
    dat: newSeqWith(2 * real_size - 1, default),
    size: size,
    real_size: real_size,
    merge: merge,
    default: default
  )

proc update[T](segt: var Segtree[T], k: Natural, val: T) =
  assert(k < segt.size)
  var key = k + segt.real_size - 1
  segt.dat[key] = val
  while key > 0:
    key = (key - 1) div 2
    segt.dat[key] = segt.merge(segt.dat[2 * key + 1], segt.dat[2 * key + 2])

proc query[T](segt: var SegTree[T], a, b, k, left, right: Natural): T =
  if right <= a or b <= left: return segt.default
  if a <= left and right <= b: return segt.dat[k]
  let mid = (left + right) div 2
  return segt.merge(segt.query(a, b, 2 * k + 1, left, mid),
                   segt.query(a, b, 2 * k + 2, mid, right))

proc query[T](segt: var SegTree[T], a, b: Natural): T =
  return segt.query(a, b, 0, 0, segt.real_size)


when isMainModule:
  let
    N = input(int, 1)
    H = input(int)
    A = input(int)
  var height_idx = newSeq[(int, int)](N)
  for i, h in H:
    height_idx[i] = (h, -i)
  height_idx.sort(cmp)
  var segt = initSegTree[int](N)
  for p in height_idx:
    let idx = -p[1]
    segt.update(idx, segt.query(0, idx) + A[idx])
  segt.query(0, N).echo
