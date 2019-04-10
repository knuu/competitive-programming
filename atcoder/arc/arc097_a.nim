# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    S = getLine
    K = getInteger
    N = S.len
  var strs = initSet[string]()
  for i in 0..<N:
    for j in (i)..<min(i + K, N):
      strs.incl(S[i..j])
  var ss = newSeq[string]()
  for s in strs:
    ss.add(s)
  ss.sort(cmp)
  ss[K-1].echo
