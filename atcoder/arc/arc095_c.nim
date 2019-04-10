# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc check(board: seq[seq[int]]): bool =
  let
    H = board.len
    W = board[0].len
  var used = newSeqWith(W, false)
  var non_pair_cnt = 0
  for i in 0..<W:
    if used[i]:
      continue
    else:
      used[i] = true
      var flag = false
      for j in 0..<W:
        if not used[j] and (0..<H).allIt(board[it][i] == board[H - 1 - it][j]):
          flag = true
          used[j] = true
          break
      if not flag:
        if (0..<H).allIt(board[it][i] == board[H - 1 - it][i]):
          non_pair_cnt.inc
        else:
          return false
  return non_pair_cnt <= 1

proc dfs(board: seq[seq[int]], left, right, center, rest: var seq[int]): bool =
  if rest.len == 0:
    let
      H = board.len
      W = board[0].len
    var tmp_board = newSeqWith(H, newSeq[int](W))
    if center.len > 0:
      tmp_board[H div 2] = board[center[0]]
    for i in 0..<(H div 2):
      tmp_board[i] = board[left[i]]
      tmp_board[H - i - 1] = board[right[i]]
    return check(tmp_board)
  if board.len mod 2 == 1 and center.len == 0:
    center.add(rest.pop)
    if dfs(board, left, right, center, rest):
      return true
    for i in 0..<rest.len:
      swap(center[0], rest[i])
      if dfs(board, left, right, center, rest):
        return true
      swap(center[0], rest[i])
    rest.add(center.pop)
  else:
    left.add(rest.pop)
    right.add(rest.pop)
    if (dfs(board, left, right, center, rest)):
      return true
    for i in 0..<rest.len:
      swap(right[^1], rest[i])
      if dfs(board, left, right, center, rest):
        return true
      swap(right[^1], rest[i])
    rest.add(right.pop)
    rest.add(left.pop)
  return false

when isMainModule:
  let
    tmp = getIntSeq
    (H, W) = (tmp[0], tmp[1])
  var
    board = newSeqWith(H, newSeq[int](W))
  for i in 0..<H:
    var tmp = getLine
    for j, c in tmp:
      board[i][j] = c.ord - 'a'.ord
  var left, right, center, rest = newSeq[int]()
  for i in 0..<H:
    rest.add(i)
  echo(if dfs(board, left, right, center, rest): "YES" else: "NO")
