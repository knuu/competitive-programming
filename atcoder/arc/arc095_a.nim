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
  var X = getIntSeq
  var X_idx = newSeq[(int, int)](N)
  for i, x in X:
    X_idx[i] = (x, i)
  X_idx.sort(cmp)
  var ans = newSeq[int](N)
  for i, p in X_idx:
    let (x, idx) = p
    if i < N div 2:
      ans[idx] = X_idx[N div 2][0]
    else:
      ans[idx] = X_idx[N div 2 - 1][0]
  for i, x in ans:
    echo(x)
