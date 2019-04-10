# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc rec(i, j, k, N: int, dp: var seq[seq[seq[float]]]): float =
  if i + j + k == 0:
    return 0.0
  if dp[i][j][k] >= 0.0:
    return dp[i][j][k]

  result = N.float
  if i > 0:
    result += rec(i - 1, j, k, N, dp) * i.float
  if j > 0:
    result += rec(i + 1, j - 1, k, N, dp) * j.float
  if k > 0:
    result += rec(i, j + 1, k - 1, N, dp) * k.float
  result /= (i + j + k).float
  dp[i][j][k] = result


when isMainModule:
  let
    N = getInteger
    A = getIntSeq
  var
    dp = newSeqWith(N + 1, newSeqWith(N + 1, newSeqWith(N + 1, -1.0)))
    ans = 0.0
    counter = newSeq[int](4)
  for a in A:
    counter[a] += 1
  rec(counter[1], counter[2], counter[3], N, dp).echo
