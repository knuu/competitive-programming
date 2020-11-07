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

proc get_sieve(max_num: int): seq[bool] =
  return sieve



when isMainModule:
  let
    (N, M) = input(int, 2)
  var A = newSeq[int](N)
  for i in 0..<N:
    A[i] = input(int, 1)
  let max_num = A.max

  var
    ret = newSeqWith(max_num + 1, true)
    prev = newSeq[int](max_num + 1)
  ret[0] = false
  ret[1] = false
  for i in 2..max_num:
    if sieve[i]:
      prev[i] = i
      var j = 2 * i
      while j <= max_num:
        sieve[j] = false
        prev[j] = i
        j += i

  var ans = newSeqWith(M, N)
  for a in A:
    if a == 1:
      for i in 0..<M:
        ans[i].dec
    else:
      var
        factor_set = initSet[int]()
        val = a
      while val > 1:
        factor_set.incl(prev[val])
        val = val div prev[val]

  for x in ans:
    x.echo
