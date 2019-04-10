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
    (H, W) = (tmp[0], tmp[1])
  var dist = newSeq[seq[int]](10)
  for i in 0..<10:
    dist[i] = getIntSeq
  for k in 0..9:
    for i in 0..9:
      for j in 0..9:
        dist[i][j] = dist[i][j].min(dist[i][k] + dist[k][j])
  var ans = 0
  for i in 0..<H:
    for x in getIntSeq:
      if x != -1:
        ans += dist[x][1]
  ans.echo
