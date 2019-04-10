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
  var west, east = newSeqWith(N + 1, 0)
  for i, d in getLine:
    if d == 'W':
      west[i + 1] = 1
    else:
      east[i + 1] = 1
    west[i + 1] += west[i]
    east[i + 1] += east[i]
  var ans = N
  for i in 0..<N:
    ans = min(ans, west[i] + east[N] - east[i + 1])
  ans.echo
