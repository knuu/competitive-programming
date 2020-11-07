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
    (N, W) = (tmp[0], tmp[1])
  var dp = newSeqWith(N + 1, newSeq[int64](W + 1))
  for i in 0..<N:
    let
      item = getIntSeq
      (w, v) = (item[0], item[1])
    for j in 0..W:
      if j - w >= 0:
        dp[i + 1][j] = max(dp[i][j], dp[i][j - w] + v.int64)
      else:
        dp[i + 1][j] = dp[i][j]
  dp[^1].max.echo
