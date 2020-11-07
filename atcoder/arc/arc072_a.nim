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

proc calc(A: seq[int]): int =
  var
    is_pos = (A[0] > 0).int
    cumsum = 0
  for a in A:
    cumsum += a
    if is_pos == 1 and cumsum <= 0:
      result += -cumsum + 1
      cumsum = 1
    elif is_pos == 0 and cumsum >= 0:
      result += cumsum + 1
      cumsum = -1
    is_pos = is_pos xor 1


when isMainModule:
  let
    N = input(int, 1)
  var
    A = input(int)
    ans_neg, ans_pos: int
  if A[0] < 0:
    ans_neg = A.calc
    ans_pos = -A[0] + 1
    A[0] = 1
    ans_pos += A.calc
  elif A[0] > 0:
    ans_pos = A.calc
    ans_neg = A[0] + 1
    A[0] = -1
    ans_neg += A.calc
  else:
    A[0] = 1
    ans_pos = A.calc + 1
    A[0] = -1
    ans_neg = A.calc + 1
  min(ans_pos, ans_neg).echo
