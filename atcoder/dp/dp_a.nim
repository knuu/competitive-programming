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
    H = getIntSeq
  var dp = newSeqWith(N, 1e9.int)
  dp[0] = 0
  for i, h in H:
    for j in @[i + 1, i + 2]:
      if j < N:
        dp[j] = min(dp[j], dp[i] + abs(H[i] - H[j]))
  dp[^1].echo
