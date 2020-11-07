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

proc popcount[T: int](a: T): cint {. importc: "__builtin_popcountl", nodecl, nosideeffect.}

proc dist(i, state: int): int =
  let left_mask = ((1 shl i) - 1)
  result = i - (state and left_mask).popcount

proc flip(i, state: int): int =
  let right_mask = not ((1 shl (i+1)) - 1)
  result = (state and right_mask).popcount



when isMainModule:
  let
    N = input(int, 1)
    A = input(int)
    B = input(int)

  var dp = newSeqWith(1 shl N, newSeqWith(N, INF))
  for i in 0..<N:
    dp[1 shl i][i] = i
  for state in 1..<dp.len:
    for i in 0..<N:
      let prev_val = if (dist(i, state) + flip(i, state)) mod 2 == 0: A[i] else: B[i]
      if dp[state][i] == INF:
        continue
      for j in 0..<N:
        if (state shr j and 1) == 1:
          continue
        let val = if (dist(j, state) + flip(j, state)) mod 2 == 0: A[j] else: B[j]
        if prev_val > val:
          continue
        dp[state or (1 shl j)][j] = dp[state or (1 shl j)][j].min(dp[state][i] + dist(j, state))
  var ans = dp[^1].min
  (if ans == INF: -1 else: ans).echo
