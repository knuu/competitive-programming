# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    N = getInteger
  var A = getBigIntSeq
  for i in 0..<(N - 1):
    A[i + 1] += A[i]
  var cnt = initTable[int64, int64]()
  for a in A:
    cnt[a] = cnt.getOrDefault(a) + 1

  var ans = 0.int64

  for k, v in cnt.pairs:
    if k == 0:
      ans += v
    ans += v * (v - 1.int64) div 2.int64
  ans.echo
