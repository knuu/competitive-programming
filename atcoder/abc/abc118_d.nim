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

const match = @[0, 2, 5, 5, 4, 5, 6, 3, 7, 6]

proc rec(res: int, A: seq[int], memo: var seq[int], memo2: var seq[bool]): int =
  if res == 0:
    return 0
  if res < 0:
    return -1
  if memo2[res]:
    return memo[res]
  result = -1
  for a in A:
    let ret = rec(res - match[a], A, memo, memo2)
    if ret >= 0:
      result = max(result, ret + 1)
  memo2[res] = true
  if result >= 0:
    memo[res] = result


when isMainModule:
  let
    (N, M) = input(int, 2)
  var A = input(int)
  var
    res = N
    memo = newSeqWith(N+1, -1)
    memo2 = newSeqWith(N+1, false)

  A.sort(cmp)
  while res > 0:
    var
      max_len, num = -1
    for j in countdown(A.len - 1, 0):
      let cand = rec(res - match[A[j]], A, memo, memo2)
      if cand > max_len:
        max_len = cand
        num = A[j]
    res -= match[num]
    stdout.write(num)
  echo()
