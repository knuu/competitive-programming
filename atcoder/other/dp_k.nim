# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc dfs(k: int, arr: seq[int], memo: var seq[int]): int =
  if k < 0:
    return 1
  if memo[k] != -1:
    return memo[k]
  result = 0
  for a in arr:
    if dfs(k - a, arr, memo) == 0:
      result = 1
      break
  memo[k] = result

when isMainModule:
  let
    tmp = getIntSeq
    (N, K) = (tmp[0], tmp[1])
    A = getIntSeq
  var dp = newSeqWith(K + 1, -1)
  echo(if dfs(K, A, dp) == 1: "First" else: "Second")
