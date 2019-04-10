# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)



when isMainModule:
  var isPrime = newSeqWith(1e5.int + 1, true)
  isPrime[0] = false
  isPrime[1] = false
  for i in 2..1e5.int:
    if isPrime[i]:
      for j in countup(2 * i, 1e5.int, i):
        isPrime[j] = false

  var similar = newSeq[int](1e5.int + 1)
  for i in 0..1e5.int:
    similar[i] = (isPrime[i] and isPrime[(i + 1) div 2]).int
  for i in 0..<1e5.int:
    similar[i + 1] += similar[i]

  for _ in 0..<getInteger:
    let query = getIntSeq
    echo(similar[query[1]] - similar[query[0] - 1])
