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
  var points = newSeq[(int, int)](N)
  for i in 0..<N:
    let tmp = getIntSeq
    points[i] = (tmp[0], tmp[1])
  let n_trial = 1e7.int / 2.0
  var count = newSeq[int](N)
  var theta = 0.float64
  while theta < arccos(-1.0) * 2:
    let
      x = 1e9 * cos(theta)
      y = 1e9 * sin(theta)
    var
      min_dist = 1e18
      min_idx = 0
    for i, point in points:
      let
        (px, py) = point
        dist = hypot(px.float64 - x, py.float64 - y)
      if dist < min_dist:
        min_dist = dist
        min_idx = i
    count[min_idx].inc
    theta += arccos(-1.0) * 2.float64 / n_trial.float64
  for c in count:
    echo(c.float64 / n_trial.float64)
