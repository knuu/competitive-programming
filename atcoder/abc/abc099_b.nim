# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    tmp = getIntSeq
    (a, b) = (tmp[0], tmp[1])
  for i in 1..999:
    if i * (i + 1) div 2 - a == (i + 1) * (i + 2) div 2 - b and i * (i + 1) div 2 - a > 0:
        echo(i * (i + 1) div 2 - a)
