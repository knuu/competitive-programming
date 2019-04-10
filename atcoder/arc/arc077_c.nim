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
    (N, M) = (tmp[0], tmp[1])
  var A = getIntSeq
  A = A.mapIt(it - 1)
  var
    button = newSeqWith(M, newSeq[int]())
    acc = newSeq[int](M + 1)
  for i in 1..<N:
    button[A[i]].add(i)
    if A[i - 1] > A[i]:
      acc[0].inc
      acc[A[i]].dec
      acc[A[i - 1] + 1].inc
      acc[^1].dec
    else:
      acc[A[i - 1] + 1].inc
      acc[A[i]].dec
  for i in 0..<M:
    acc[i + 1] += acc[i]

  var cnt = 0
  for i in 1..<N:
    cnt += min((A[i] - A[i - 1] + M) mod M, 1 + A[i] mod M)

  var ans = cnt
  for i in 0..<(M - 1):
    cnt += button[i].mapIt((A[it] + M - A[it - 1]) mod M - 1).sum - acc[i]
    ans = ans.min(cnt)
  ans.echo
