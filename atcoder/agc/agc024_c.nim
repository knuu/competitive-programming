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
  var A = newSeq[int64](N)
  for i in 0..<N:
    A[i] = getBiggestInteger
  if A[0] != 0:
    echo(-1)
    quit()
  for i in 0..<(N - 1):
    if A[i] + 1 < A[i + 1]:
      echo(-1)
      quit()
  var ans = 0.int64
  for i in countdown(N - 2, 0):
    if A[i + 1] == A[i] + 1:
      ans.inc
    else:
      ans += A[i + 1]
  ans.echo
