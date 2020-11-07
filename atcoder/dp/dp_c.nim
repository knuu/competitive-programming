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
  var dp = newSeqWith(N + 1, newSeq[int](3))
  dp[0] = @[0, 0, 0]
  for i in 0..<N:
    let act = getIntSeq
    for j in 0..<3:
      for k in 0..<3:
        if j == k:
          continue
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + act[j])
  dp[^1].max.echo
