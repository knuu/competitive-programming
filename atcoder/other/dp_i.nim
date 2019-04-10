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
    P = getLine.split.map(parseFloat)
  var dp = newSeqWith(N + 1, newSeq[float](N + 1))
  dp[0][0] = 1.0
  for i, p in P:
    for j in 0..i:
      dp[i + 1][j + 1] += dp[i][j] * p
      dp[i + 1][j] += dp[i][j] * (1 - p)
  let over_mid = (N + 2) div 2
  dp[^1][over_mid..^1].sum.formatFloat.echo
