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
    (N, Q) = input(int, 2)
    s = input(string, 1)
  var queries = newSeq[(char, int)](Q)

  for i in 0..<Q:
    let (t, d) = input(string, 2)
    queries[i] = (t[0], if d[0] == 'L': -1 else: 1)

  var (left, right) = (-1, N)
  while left + 1 < right:
    let mid = (left + right) div 2

    var pos = mid
    for query in queries:
      let (t, d) = query
      if s[pos] == t:
        pos += d
      if pos < 0 or N <= pos:
        break
    if pos < 0:
      left = mid
    else:
      right = mid
  var drop = left + 1

  (left, right) = (-1, N)
  while left + 1 < right:
    let mid = (left + right) div 2

    var pos = mid
    for query in queries:
      let (t, d) = query
      if s[pos] == t:
        pos += d
      if pos < 0 or N <= pos:
        break
    if pos >= N:
      right = mid
    else:
      left = mid

  drop += N - right
  echo N - drop
