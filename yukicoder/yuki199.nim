# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

type
  Point[T] = object
    x, y: T

proc initPoint[T](x, y: T): Point[T] =
  Point[T](x: x, y: y)

proc `+`[T](a, b: Point[T]): Point[T] =
  initPoint(a.x + b.x, a.y + b.y)

proc `-`[T](a, b: Point[T]): Point[T] =
  initPoint(a.x - b.x, a.y - b.y)

proc det[T](a, b: Point[T]): T =
  a.x * b.y - a.y * b.x

proc convex_hull[T](points: seq[Point[T]]): seq[Point[T]] =
  var sorted_points = points
  sorted_points.sort do (p1, p2: Point[T]) -> int:
    result = cmp(p1.x, p2.x)
    if result == 0:
      result = cmp(p1.y, p2.y)
  var lower_hull = sorted_points.get_bounds
  sorted_points.reverse
  result = sorted_points.get_bounds
  discard lower_hull.pop
  discard result.pop
  for point in lower_hull:
    result.add(point)

proc get_bounds[T](points: var seq[Point[T]]): seq[Point[T]] =
  result = @[points[0], points[1]]
  for point in points[2..^1]:
    while result.len > 1 and (result[^1] - result[^2]).det(point - result[^1]) <= 0:
      discard result.pop
    result.add(point)

when isMainModule:
  var points = newSeq[Point[int]](5)
  for i in 0..<5:
    let tmp = getIntSeq
    points[i] = initPoint(tmp[0], tmp[1])
  echo(if points.convex_hull.len == 5: "YES" else: "NO")
