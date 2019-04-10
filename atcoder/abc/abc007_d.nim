# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc digitDP(N: string): int64 =
  let L = N.len
  var dp = newSeqWith(L + 1, newSeqWith(2, newSeqWith(2, 0.int64)))
  dp[0][0][0] = 1.int64
  for l in 0..<L:
    for flag in 0..1:
      for cond in 0..1:
        if cond == 1:
          for i in 0..<10:
            if i == 4 or i == 9:
              dp[l + 1][1][1] += dp[l][flag][1]
            else:
              dp[l + 1][flag][1] += dp[l][flag][1]
        else:
          for i in 0..<(N[l].ord - '0'.ord):
            if i == 4 or i == 9:
              dp[l + 1][1][1] += dp[l][flag][0]
            else:
              dp[l + 1][flag][1] += dp[l][flag][0]
          if (N[l].ord - '0'.ord) == 4 or (N[l].ord - '0'.ord) == 9:
            dp[l + 1][1][0] += dp[l][flag][0]
          else:
            dp[l + 1][flag][0] += dp[l][flag][0]
  return dp[L][1].sum


when isMainModule:
  let
    num = getLine.split
    (A, B) = (num[0], num[1])
  var ans = digitDP(B) - digitDP(A)
  if '4' in A or '9' in A:
    echo(ans + 1)
  else:
    echo(ans)
