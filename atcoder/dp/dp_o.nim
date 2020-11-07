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
    N = getInteger
    MOD = 1e9.int64 + 7
  var mat = newSeqWith(N, newSeq[int]())
  for i in 0..<N:
    mat[i] = getIntSeq
  var dp = newSeq[int64](1 shl N)
  dp[0] = 1
  for bit in 0..<((1 shl N) - 1):
    dp[bit] = dp[bit] mod MOD
    let man = popcount(bit)
    for woman in 0..<N:
      if (bit shr woman and 1) == 0 and mat[man][woman] == 1:
        dp[bit or (1 shl woman)] += dp[bit]
  echo(dp[^1] mod MOD)
