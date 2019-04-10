# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    tmp = getBigIntSeq
    (N, A, B) = (tmp[0].int, tmp[1], tmp[2])
    X = getBigIntSeq
  var diff = newSeq[int64](N)
  for i in 0..<(N - 1):
    diff[i] = X[i + 1] - X[i]
  diff.sort(cmp)
  for i in 0..<(N - 1):
    diff[i + 1] += diff[i]
  var ans = diff[^1] * A
  for i in 0..<N:
    ans = min(ans, i * B + diff[N - i - 1] * A)
  ans.echo
