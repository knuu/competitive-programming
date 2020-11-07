# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

let inf = 2e9.int
var
  N, Z, W: int
  A: seq[int]
  dp: seq[seq[int]]

proc dfs(z, w: int): int =
  if z == N or w == N:
    return abs((if z == 0: Z else: A[z - 1]) - (if w == 0: W else: A[w - 1]))
  elif dp[z][w] != -1:
    return dp[z][w]
  if z <= w:
    result = 0
    for i in (w + 1)..N:
      result = result.max(dfs(i, w))
  else:
    result = inf
    for i in (z + 1)..N:
      result = result.min(dfs(z, i))
  dp[z][w] = result

when isMainModule:
  let
    tmp = getIntSeq
  (N, Z, W) = (tmp[0], tmp[1], tmp[2])
  A = getIntSeq
  dp = newSeqWith(N + 1, newSeqWith(N + 1, -1))
  dfs(0, 0).echo
