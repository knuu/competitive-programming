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

when isMainModule:
  let
    (H, W, K, V) = input(int, 4)
  var board = newSeqWith(H+1, newseq[int](W+1))
  for r in 0..<H:
    for c, val in stdin.readline.split.map(parseInt):
      board[r+1][c+1] = val
  for r in 0..H:
    for c in 0..<W:
      board[r][c+1] += board[r][c]
  for c in 0..W:
    for r in 0..<H:
      board[r+1][c] += board[r][c]

  var ans = 0
  for r1 in 0..<H:
    for c1 in 0..<W:
      for r2 in r1..<H:
        for c2 in c1..<W:
          let
            sq = board[r2+1][c2+1] - board[r2+1][c1] - board[r1][c2+1] + board[r1][c1]
            (height, width) = (r2 - r1 + 1, c2 - c1 + 1)
            cost = height * width * K + sq
          if cost <= V and height * width > ans:
            ans = height * width
  ans.echo
