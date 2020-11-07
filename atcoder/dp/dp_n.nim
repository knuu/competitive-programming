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
    A = getBigIntSeq
    inf = 1e18.int64
  var acc_A = newSeq[int64](N + 1)
  for i, a in A:
    acc_A[i + 1] = acc_A[i] + a
  var dp = newSeqWith(N + 1, newSeq[int64](N + 1))
  for width in 2..N:
    for left in 0..(N - width):
      let
        right = left + width
        cost = acc_A[right] - acc_A[left]
      dp[left][right] = inf
      for mid in (left + 1)..<right:
        dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid][right] + cost)
  dp[0][N].echo
