# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let N = getInteger
  var cnt = @[@[0, 0], @[0, 0]]
  for _ in 0..<N:
    let tmp = getIntSeq
    cnt[tmp[0] mod 2][tmp[1] mod 2].inc
  echo(if cnt.mapIt(it.mapIt(it div 2).sum).sum mod 2 == 1: "Alice" else: "Bob")
