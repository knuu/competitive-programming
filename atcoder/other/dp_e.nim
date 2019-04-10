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
    max_v = 1e5.int
    inf = W
  var
    dp = newSeqWith(N + 1, newSeqWith(max_v + 1, inf))
    ans = 0
  dp[0][0] = 0
  for i in 0..<N:
    let
      item = getIntSeq
      (w, v) = (item[0], item[1])
    for j in 0..max_v:
      if dp[i][j] == inf:
        continue
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])
      if j + v <= max_v and dp[i][j] + w <= W:
        dp[i + 1][j + v] = min(dp[i + 1][j + v], dp[i][j] + w)
        ans = max(ans, j + v)
  ans.echo
