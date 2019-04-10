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
  if A.allIt(it == 0):
    echo(0)
    quit()

  var
    abs_max = 0
    abs_max_idx = -1
  for i, a in A:
    if a.abs > abs_max.abs:
      abs_max = a
      abs_max_idx = i + 1
  echo(2 * N - 1)
  for i in 1..N:
    echo(abs_max_idx, ' ', i)
  if abs_max > 0:
    for i in 1..<N:
      echo(i, ' ', i + 1)
  else:
    for i in countdown(N, 2):
      echo(i, ' ', i - 1)
