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
  var (N, M) = (tmp[0], tmp[1])
  if N > M:
    swap(N, M)
  if N == 1:
    if M == 1:
      echo(1)
    else:
      echo(M - 2)
  else:
    echo((N - 2).int64 * (M - 2).int64)
