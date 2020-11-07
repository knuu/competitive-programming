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
    (N, K) = (tmp[0], tmp[1])
    H = getIntSeq
  var dp = newSeqWith(N, 1e9.int)
  dp[0] = 0
  for i, h in H:
    for j in 1..K:
      if i + j < N:
        dp[i + j] = min(dp[i + j], dp[i] + abs(H[i] - H[i + j]))
  dp[^1].echo
