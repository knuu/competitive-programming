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
    A = getIntSeq
    B = getIntSeq
  var ans = 0
  var MOD = newSeq[int]()
  for i in 0..30:
    MOD.add(1 shl i)

  for i in 0..28:
    var mod_A, mod_B = newSeq[int]()
    for a in A:
      mod_A.add(a and (MOD[i + 1] - 1))
    for b in B:
      mod_B.add(b and (MOD[i + 1] - 1))
    mod_B.sort(cmp)

    var cnt = 0
    for a in mod_A:
      cnt += mod_B.lowerBound(MOD[i + 1] - a) - mod_B.lowerBound(MOD[i] - a)
      cnt += mod_B.lowerBound(MOD[i + 2] - a) - mod_B.lowerBound(MOD[i + 1] + MOD[i] - a)
    echo(cnt)
    ans = ans or (MOD[i] * (cnt and 1))
  ans.echo
