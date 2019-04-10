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
  var
    (A, B, N) = (tmp[0], tmp[1], tmp[2])
    X = getLine
  for s in X:
    if s == 'S':
      A = max(A - 1, 0)
    elif s == 'C':
      B = max(B - 1, 0)
    elif A >= B:
      A = max(A - 1, 0)
    else:
      B = max(B - 1, 0)
  A.echo
  B.echo
