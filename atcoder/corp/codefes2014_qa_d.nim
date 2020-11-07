# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc popcount[T: int64|int](a: T): cint {. importc: "__builtin_popcountl", nodecl, nosideeffect.}

when isMainModule:
  let
    tmp = getLine.split
    L = tmp[0].len
    (A, K) = (tmp[0].parseBiggestInt, tmp[1].parseInt)

  let inf = 1e16.int64
  var dp = newSeqWith(L + 1, newSeqWith(1 shl 10, newSeqWith(3, inf)))
  dp[0][0][0] = 0
  var pow10 = 1.int64
  for i in 0..<L:
    pow10 *= 10
  for i in 0..<L:
    pow10 = pow10 div 10
    for j in 0..<(1 shl 10):
      for d in 0..9:
        let next_state = if popcount(j) > 0 or d != 0: j or (1 shl d) else: 0
        if popcount(next_state) > K:
          continue
        if dp[i][j][1] < inf:
          dp[i + 1][next_state][1] = min(dp[i + 1][next_state][1], dp[i][j][1] - d * pow10)
        if dp[i][j][2] < inf:
          dp[i + 1][next_state][2] = min(dp[i + 1][next_state][2], d * pow10 + dp[i][j][2])
        if dp[i][j][0] < inf:
          if d < A div pow10 mod 10:
            dp[i + 1][next_state][1] = min(dp[i + 1][next_state][1], A mod (pow10 * 10) - d * pow10)
          elif d > A div pow10 mod 10:
            dp[i + 1][next_state][2] = min(dp[i + 1][next_state][2],  d * pow10 - A mod (pow10 * 10))
          else:
            dp[i + 1][next_state][0] = dp[i][j][0]
  dp[L].mapIt(it.min).min.echo
