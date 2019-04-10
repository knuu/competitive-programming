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
  var dp = newSeq[int](N + 1)
  for i in 0..N:
    dp[i] = N - i
  var x = 6
  while x <= N:
    for i in countDown(N, 0):
      if i + x <= N:
        dp[i] = min(dp[i], dp[i + x] + 1)
    x *= 6
  x = 9
  while x <= N:
    for i in countDown(N, 0):
      if i + x <= N:
        dp[i] = min(dp[i], dp[i + x] + 1)
    x *= 9
  dp[0].echo
