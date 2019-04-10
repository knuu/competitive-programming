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
    (N, C) = (tmp[0], tmp[1])
  var colors = newSeqWith(3, newSeqWith(C, 0))
  var change = newSeq[seq[int]](C)
  for i in 0..<C:
    change[i] = getIntSeq
  for i in 0..<N:
    for j, c in getIntSeq:
      colors[(i + j) mod 3][c - 1].inc

  var ans = 1e9.int
  for i in 0..<C:
    for j in 0..<C:
      for k in 0..<C:
        if i == j or j == k or k == i:
          continue
        var cost = 0
        for col in 0..2:
          for l, c in colors[col]:
            if l != @[i, j, k][col]:
              cost += c * change[l][@[i, j, k][col]]
        ans = min(ans, cost)
  ans.echo
