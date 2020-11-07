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
  Matrix[T] = object
    data: seq[seq[T]]
    height: Natural
    width: Natural

proc `[]`(mat: Matrix, x, y: Natural): mat.T {.inline.} =
  mat.data[x][y]

proc `[]=`[T](mat: var Matrix[T], x, y: Natural, val: T) {.inline.} =
  mat.data[x][y] = val

proc initMatrix[T](arr: seq[seq[T]]): Matrix[T] =
  assert arr.len > 0 and arr[0].len > 0
  return Matrix[T](data: arr, height: arr.len, width: arr[0].len)

proc initMatrix[T](height, width: Natural): Matrix[T] =
  assert height > 0 and width > 0
  return Matrix[T](data: newSeqWith(height, newSeq[T](width)),
                   height: height, width: width)

proc unitMatrix[T](n: Natural): Matrix[T] =
  assert n > 0
  result = initMatrix[T](n, n)
  for i in 0..<n:
    result[i, i] = 1

proc echo[T](mat: Matrix[T]) =
  for row in mat.data:
    row.echo

proc dot[T](mat1: Matrix[T], mat2: Matrix[T], modulo: T): Matrix[T] =
  assert mat1.width == mat2.height
  result = initMatrix[T](mat1.height, mat2.width)
  for r in 0..<result.height:
    for c in 0..<result.width:
      for i in 0..<mat1.width:
        result[r, c] = (result[r, c] + mat1[r, i] * mat2[i, c] mod modulo) mod modulo


proc pow[T](mat: Matrix[T], k: int, modulo: T): Matrix[T] =
  echo(modulo)
  assert k >= 0
  result = unitMatrix[T](mat.height)
  var
    two_exp = mat
    res = k
  while res > 0:
    echo(res, ' ', result.data.mapIt(it.sum mod MOD).sum mod MOD)
    if res mod 2 != 0:
      result = result.dot(two_exp, modulo)
    two_exp = two_exp.dot(two_exp, modulo)
    res = res shr 1


when isMainModule:
  let
    (N, K) = input(int, 2)
  var arr = newSeq[seq[int]](N)
  for i in 0..<N:
    arr[i] = input(int)
  var mat = initMatrix[int](arr)
  var result = mat.pow(K, MOD)
  echo result.data.mapIt(it.sum mod MOD).sum mod MOD
