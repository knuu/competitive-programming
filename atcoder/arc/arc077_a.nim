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
    A = getIntSeq
  var idxes = newSeq[int](N)
  var
    left = 0
    right = N - 1
    cnt = 0
    now = N - 1
  while left <= right:
    if cnt mod 2 == 0:
      idxes[left] = now
      left.inc
    else:
      idxes[right] = now
      right.dec
    now.dec
    cnt.inc
  for i in 0..<N:
    if i > 0:
      stdout.write(' ')
    stdout.write(A[idxes[i]])
  echo()
