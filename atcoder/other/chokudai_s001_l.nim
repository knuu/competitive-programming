# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let N = getInteger
  var
    A = getIntSeq.mapIt(it - 1)
    rev = newSeq[int](N)
  for i, a in A:
    rev[a] = i
  var cnt = 0
  for i, a in A:
    if i != a:
      swap(A[i], A[rev[i]])
      swap(rev[i], rev[a])
      cnt.inc
  echo(if (N - cnt) mod 2 == 0: "YES" else: "NO")
