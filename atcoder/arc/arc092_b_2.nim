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
  var
    A, B, BB: array[200000, int64]
    b_pow: array[33, int64]
  for i in 0..32:
    b_pow[i] = 1.int64 shl i
  for i in 0..<200000:
    BB[i] = b_pow[32]
  for i, a in getBigIntSeq:
    A[i] = a
  for i, b in getBigIntSeq:
    B[i] = b
  var ans = 0.int64
  for bit in 0..28:
    for i in 0..<N:
      BB[i] = B[i] and (b_pow[bit + 1] - 1.int64)
    BB.sort(cmp)
    var cnt = 0
    for i in 0..<N:
      let a = A[i] and (b_pow[bit + 1] - 1.int64)
      cnt += BB.lowerBound(b_pow[bit + 1] - a) - BB.lowerBound(b_pow[bit] - a)
      cnt += BB.lowerBound(b_pow[bit + 2] - a) - BB.lowerBound((b_pow[bit] or b_pow[bit + 1]) - a)
    if (cnt and 1) == 1:
      ans = ans or b_pow[bit]
  ans.echo
