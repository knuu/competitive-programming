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

proc rec(idx: int, modulo: int, flag: bool, digit: string, D: int, memo: var seq[seq[seq[int]]]): int =
  if idx == digit.len:
    return (modulo == 0).int
  if memo[idx][modulo][flag.int] != -1:
    return memo[idx][modulo][flag.int]

  if flag:
    result += rec(idx + 1, (modulo + D - (digit[idx].ord - '0'.ord)) mod D, true, digit, D, memo)
    for i in 0..<(digit[idx].ord - '0'.ord):
      result = (result + rec(idx + 1, (modulo + D - i) mod D, false, digit, D, memo)) mod MOD
  else:
    for i in 0..9:
      result = (result + rec(idx + 1, (modulo + D - i) mod D, false, digit, D, memo)) mod MOD
  memo[idx][modulo][flag.int] = result

when isMainModule:
  let
    K = input(string, 1)
    D = input(int, 1)
  var memo = newSeqWith(K.len, newSeqWith(D, newSeqWith(2, -1)))
  echo((rec(0, 0, true, K, D, memo) - 1 + MOD) mod MOD)
