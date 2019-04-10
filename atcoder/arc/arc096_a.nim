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
  var (A, B, C, X, Y) = (tmp[0], tmp[1], tmp[2], tmp[3], tmp[4])
  if X > Y:
    swap(A, B)
    swap(X, Y)
  var ans = 2 * C * X + (Y - X) * min(B, 2 * C)
  ans = min(ans, X * min(A, 2 * C) + Y * min(B, 2 * C))
  ans.echo
