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

proc dfs(i, j: int, S: seq[int], memo: var seq[seq[int]]): int =
  if i == S.len:
    return (j == 3).int
  if memo[i][j] != -1:
    return memo[i][j]

  # 使わない場合
  if S[i] == 3:
    result += 3 * dfs(i+1, j, S, memo) mod MOD
  else:
    result += dfs(i+1, j, S, memo) mod MOD

  # 使う場合
  if j < 3 and (S[i] == j or S[i] == 3):
    result += dfs(i+1, j+1, S, memo)
    result = result mod MOD
  memo[i][j] = result

when isMainModule:
  let
    S_tmp = input(string, 1)
    L = S_tmp.len
  var
    S = newSeq[int](L)
    memo = newSeqWith(L + 1, newSeqWith(4, -1))
  for i, s in S_tmp:
    case s:
      of 'A':
        S[i] = 0
      of 'B':
        S[i] = 1
      of 'C':
        S[i] = 2
      else:
        S[i] = 3
  dfs(0, 0, S, memo).echo
