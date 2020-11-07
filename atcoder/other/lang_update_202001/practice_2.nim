import algorithm, complex, future, macros, math, rationals, sets,
    sequtils, strutils, tables # for 0.13.0
# import algorithm, bitops, complex, deques, heapqueue, lenientops, macros, math, queues, rationals, sets, sequtils, strformat, strscans, strutils, sugar, tables # for 0.19

# ----- input macro by nimon -----

macro unpack*(input: seq; count: static[int]): untyped =
  result = quote do: ()
  when NimMajor == 0 and NimMinor <= 13:
    for i in 0..<count: result[0].add quote do: `input`[`i`]
  else:
    for i in 0..<count: result.add quote do: `input`[`i`]

## count == 0 のとき unpackしない(seq)
## count >  0 のとき count個分 unpack した結果の tuple を返す
type UnselectableTypeError = object of Exception
template input*(typ: typedesc; count: Natural = 0): untyped =
  let line = stdin.readLine.split
  when count == 0:
    when typ is int: line.map(parseInt)
    elif typ is float: line.map(parseFloat)
    elif typ is string: line
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")
  else:
    when typ is int: line.map(parseInt).unpack(count)
    elif typ is float: line.map(parseFloat).unpack(count)
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


proc merge(left, right: int; A: seq[char]): seq[char] =
  if left + 1 == right:
    return @[A[left]]
  let mid = (left + right) shr 1
  var
    l_arr = merge(left, mid, A)
    r_arr = merge(mid, right, A)
  result = newseq[char]()
  while l_arr.len > 0 and r_arr.len > 0:
    echo("? ", l_arr[0], ' ', r_arr[0])
    if input(string, 1) == "<":
      result.add(l_arr[0])
      l_arr = l_arr[1..^1]
    else:
      result.add(r_arr[0])
      r_arr = r_arr[1..^1]
  if l_arr.len > 0:
    for x in l_arr:
      result.add(x)
  if r_arr.len > 0:
    for x in r_arr:
      result.add(x)


proc solve26(N: int) =
  var A = newseq[char](N)
  for i in 0..<N:
    A[i] = chr(ord(i) + ord('A'))
  let ans = merge(0, N, A)
  stdout.write("! ")
  for x in ans:
    stdout.write(x)
  echo()

proc solve5() =
  let S = "ABCDE"
  var
    cands = newseq[seq[char]]()
    perm = @['A', 'B', 'C', 'D', 'E']
  cands.add(perm)
  while nextPermutation(perm):
    cands.add(perm)

  while cands.len > 1:
    var mp = newTable[(char, char), int]()
    for cand in cands:
      for i in 0..<5:
        for j in (i+1)..<5:
          mp[(cand[i], cand[j])] = mp.getOrDefault((cand[i], cand[j])) + 1

    var
      mc = 1000
      mi, mj: int
    for i in 0..<5:
      for j in (i+1)..<5:
        let tc = max(mp.getOrDefault((S[i], S[j])), mp.getOrDefault((S[j], S[i])))
        if tc < mc:
          mc = tc
          (mi, mj) = (i, j)

    echo("? ", S[mi], ' ', S[mj])
    if input(string, 1) == "<":
      cands.keepIf(proc (x: seq[char]): bool = x.find(S[mi]) < x.find(S[mj]))
    else:
      cands.keepIf(proc (x: seq[char]): bool = x.find(S[mi]) > x.find(S[mj]))
  echo("! ", cast[string](cands[0]))


when isMainModule:
  let (N, Q) = input(int, 2)
  if N == 5:
    solve5()
  else:
    solve26(N)
