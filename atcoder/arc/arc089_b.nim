# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc get_range_sum(arr: var array[2001, array[2001, int]], sx, sy, tx, ty: int): int =
  return arr[tx][ty] + arr[sx - 1][sy - 1] - arr[sx - 1][ty] - arr[tx][sy - 1]

proc calc_sq_sum(arr: var array[2001, array[2001, int]], sx, sy, K: int): int =
  return arr.get_range_sum(1, 1, sx, sy) + arr.get_range_sum(sx + 1, sy + 1, sx + K, sy + K) + arr.get_range_sum(sx + K + 1, sy + K + 1, 2 * K, 2 * K) + arr.get_range_sum(1, sy + K + 1, sx, 2 * K) + arr.get_range_sum(sx + K + 1, 1, 2 * K, sy)

when isMainModule:
  let
    tmp = getIntSeq
    (N, K) = (tmp[0], tmp[1])
  var black, white: array[2001, array[2001, int]]
  for i in 0..(2 * K):
    for j in 0..(2 * K):
      black[i][j] = 0
      white[i][j] = 0
  for i in 0..<N:
    let
      p = getLine.split
      (x, y, c) = (p[0].parseInt mod (2 * K), p[1].parseInt mod (2 * K), p[2])
    if c == "B":
      black[x + 1][y + 1].inc
    else:
      white[x + 1][y + 1].inc
  for i in 0..(2 * K):
    for j in 0..<(2 * K):
      black[i][j + 1] += black[i][j]
      white[i][j + 1] += white[i][j]
  for i in 0..(2 * K):
    for j in 0..<(2 * K):
      black[j + 1][i] += black[j][i]
      white[j + 1][i] += white[j][i]

  #for board in @[black, white]:
  #  for row in board[0..2*K]:
  #    row[0..2*K].mapIt(it.intToStr).join(" ").echo
  #  echo()

  var
    ans = 0
    n_black = black[2 * K][2 * K]
    n_white = white[2 * K][2 * K]
  for i in 0..<K:
    for j in 0..<K:
      let
        b = black.calc_sq_sum(i, j, K)
        w = white.calc_sq_sum(i, j, K)
      ans = max(ans, max(b + n_white - w, w + n_black - b))
  ans.echo
