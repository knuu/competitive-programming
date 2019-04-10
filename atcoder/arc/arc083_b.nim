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
  var roads = newSeqWith(N, newSeq[int64](N))
  for i in 0..<N:
    roads[i] = getBigIntSeq

  var ans = 0.int64
  for i in 0..<N:
    if roads[i][i] > 0:
      echo(-1)
      quit()
    for j in i..<N:
      ans += roads[i][j]

  for k in 0..<N:
    for i in 0..<N:
      for j in 0..<N:
        if roads[i][k] + roads[k][j] < roads[i][j]:
          echo(-1)
          quit()

  for i in 0..<N:
    for j in (i + 1)..<N:
      for k in 0..<N:
        #echo(i, ',', j, ',', k, ':', roads[i][j], ',', roads[i][k], ',', roads[k][j])
        if i != k and j != k and roads[i][j] == roads[i][k] + roads[k][j]:
          ans -= roads[i][j]
          break
  ans.echo
