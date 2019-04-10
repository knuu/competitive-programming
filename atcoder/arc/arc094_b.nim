# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let Q = getInteger
  for _ in 0..<Q:
    let tmp = getBigIntSeq
    var (A, B) = (tmp[0], tmp[1])
    if A > B:
      swap(A, B)
    if B - A <= 1:
      echo(2 * A - 2)
    else:
      var C = ((A * B).float64.sqrt + 1e-9).int64
      if C * C == A * B:
        C.dec
      if C * (C + 1) >= A * B:
        echo(2 * C - 2)
      else:
        echo(2 * C - 1)
