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
    inf = 1e9.int
  assert(N <= 3000)
  var W: array[3001, int]
  for i, x in getIntSeq:
    W[i + 1] = x
    W[i + 1] += W[i]
  var
    dp, root: array[3000, array[3000, int]]
  for i in 0..<N:
    dp[i].fill(inf)
    dp[i][i] = W[i + 1] - W[i]
    root[i][i] = i
  for length in 2..N:
    for left in 0..(N - length):
      let
        right = left + length - 1
        weight = W[right + 1] - W[left]
      for mid in root[left][right - 1]..root[left + 1][right]:
        if mid + 1 <= right and dp[left][right] > dp[left][mid] + dp[mid + 1][right] + weight:
          root[left][right] = mid
          dp[left][right] = dp[left][mid] + dp[mid + 1][right] + weight
  (dp[0][N - 1] - W[N]).echo
