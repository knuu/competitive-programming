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
    (H, W) = (tmp[0], tmp[1])
  var board = newSeq[string](H)
  for i in 0..<H:
    board[i] = getLine
  var dp = newSeqWith(H, newSeq[int64](W))
  dp[0][0] = 1
  let MOD = 1e9.int64 + 7
  for r in 0..<H:
    for c in 0..<W:
      if board[r][c] == '#':
        continue
      if r > 0 and c > 0:
        dp[r][c] = (dp[r - 1][c] + dp[r][c - 1]) mod MOD
      elif r > 0:
        dp[r][c] = dp[r - 1][c]
      elif c > 0:
        dp[r][c] = dp[r][c - 1]
  dp[^1][^1].echo
