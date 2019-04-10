# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    D = getInteger
    N = getLine
    L = N.len
  var
    dp = newSeqWith(L + 1, newSeqWith(D, newSeqWith(2, 0.int64)))
    MOD = (1e9.int + 7).int64
  dp[0][0][0] = 1
  for l in 0..<L:
    for d in 0..<D:
      for cond in 0..1:
        if cond == 1:
          for i in 0..<10:
            dp[l + 1][(d + i) mod D][1] += dp[l][d][1]
            dp[l + 1][(d + i) mod D][1] = dp[l + 1][(d + i) mod D][1] mod MOD
        else:
          for i in 0..<(N[l].ord - '0'.ord):
            dp[l + 1][(d + i) mod D][1] += dp[l][d][0]
            dp[l + 1][(d + i) mod D][1] = dp[l + 1][(d + i) mod D][1] mod MOD
          dp[l + 1][(d + (N[l].ord - '0'.ord)) mod D][0] += dp[l][d][0]
          dp[l + 1][(d + (N[l].ord - '0'.ord)) mod D][0] = dp[l + 1][(d + (N[l].ord - '0'.ord)) mod D][0] mod MOD
  echo((dp[L][0][0] + dp[L][0][1] - 1 + MOD) mod MOD)
