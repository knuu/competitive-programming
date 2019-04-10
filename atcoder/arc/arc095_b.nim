# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    N = getInteger
  var A = getIntSeq
  let a1 = A.max
  var A_tmp = newSeq[(int, int)]()
  for i, a in A:
    if a == a1:
      continue
    elif a > (a1 + 1) div 2:
      A_tmp.add((a1 - a, a))
    else:
      A_tmp.add((a, a))
  A_tmp.sort(cmp)
  echo(a1, ' ', A_tmp[^1][1])
