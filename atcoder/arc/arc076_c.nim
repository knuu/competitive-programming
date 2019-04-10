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
    (R, C, N) = (tmp[0], tmp[1], tmp[2])
  var points = newSeq[(int, int, int, int)](N)
  for i in 0..<N:
    let tmp = getIntSeq
    points[i] = (tmp[0], tmp[1], tmp[2], tmp[3])
  var sides = newSeq[(int, int)]()
  for i, point in points:
    var (r1, c1, r2, c2) = point
    if (r1 in @[0, R] or c1 in @[0, C]) and (r2 in @[0, R] or c2 in @[0, C]):
      for p in @[(r1, c1), (r2, c2)]:
        let (r, c) = p
        if r == 0:
          sides.add((c, i))
        elif r == R:
          sides.add((C + R + (C - c), i))
        elif c == 0:
          sides.add((C + R + C + (R - r), i))
        else:
          sides.add((C + r, i))
  sides.sort(cmp)
  var stack = newSeq[int]()
  for point in sides:
    let (_, idx) = point
    if stack.len == 0 or stack[^1] != idx:
      stack.add(idx)
    else:
      discard stack.pop
  echo(if stack.len == 0: "YES" else: "NO")
