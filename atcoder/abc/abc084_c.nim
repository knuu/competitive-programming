# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let N = getInteger
  var C, S, F = newSeq[int](N - 1)
  for i in 0..<(N - 1):
    let tmp = getIntSeq
    C[i] = tmp[0]
    S[i] = tmp[1]
    F[i] = tmp[2]
  for i in 0..<(N - 1):
    var ans = S[i] + C[i]
    for j in (i + 1)..<(N - 1):
      var d = max(ans - S[j], 0) div F[j]
      if max(ans - S[j], 0) mod F[j] != 0:
        d.inc
      ans = S[j] + d * F[j] + C[j]
    ans.echo
  echo(0)
