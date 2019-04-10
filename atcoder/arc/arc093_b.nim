# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

let K = 50

proc draw(board: var seq[seq[char]], rest_tmp, start: int, color: char): seq[seq[char]] =
  var rest = rest_tmp
  for i in countup(start, 2 * K - 1, 2):
    for j in countup(0, 2 * K - 1, 2):
      if rest == 0:
        return board
      board[i][j] = color
      rest.dec
  return board

when isMainModule:
  let
    tmp = getIntSeq
    (A, B) = (tmp[0], tmp[1])
  var board = newSeqWith(2 * K, newSeq[char](2 * K))
  for i in 0..<K:
    for j in 0..<(2 * K):
      board[i][j] = '#'
      board[i + K][j] = '.'
  board = draw(board, A - 1, 0, '.')
  board = draw(board, B - 1, K + 1, '#')
  echo(2 * K, ' ', 2 * K)
  for row in board:
    for c in row:
      stdout.write(c)
    echo()
