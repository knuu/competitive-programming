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
    (N, M) = (tmp[0], tmp[1])
  var cakes = newSeqWith(N, newSeq[int64]())
  for i in 0..<N:
    cakes[i] = getBigIntSeq
  var ans = 0.int64
  for bit in 0..<(1 shl 3):
    for i in 0..<N:
      for j in 0..<3:
        if (bit shr j and 1) == 1:
          cakes[i][j] *= -1.int64
    var dp = newSeqWith(N + 1, newSeqWith(M + 1, -1e13.int64))
    dp[0][0] = 0
    for i in 0..<N:
      for j in 0..M:
        if j == 0:
          dp[i + 1][j] = dp[i][j]
        else:
          dp[i + 1][j] = max(dp[i][j], dp[i][j - 1] + cakes[i].sum)
    for i in 0..<N:
      for j in 0..<3:
        if (bit shr j and 1) == 1:
          cakes[i][j] *= -1.int64
    ans = max(ans, dp[N][M])
  ans.echo
