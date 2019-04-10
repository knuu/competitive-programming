# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let N = getLine
  var dp = newSeqWith(N.len + 1, newSeqWith(2, newSeqWith(11, 0)))
  dp[0][1][0] = 1
  for i in 0..<N.len:
    for k in 0..9:
      for d in 0..9:
        if d == 1:
          dp[i + 1][0][k + 1] += dp[i][0][k]
        else:
          dp[i + 1][0][k] += dp[i][0][k]
        if N[i].ord - '0'.ord > d:
          if d == 1:
            dp[i + 1][0][k + 1] += dp[i][1][k]
          else:
            dp[i + 1][0][k] += dp[i][1][k]
        elif N[i].ord - '0'.ord == d:
          if d == 1:
            dp[i + 1][1][k + 1] += dp[i][1][k]
          else:
            dp[i + 1][1][k] += dp[i][1][k]

  var ans = 0
  for k in 1..9:
    for j in 0..1:
      ans += dp[N.len][j][k] * k
  ans.echo
