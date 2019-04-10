import strutils, sequtils
let
  input = stdin.readline.split.map(parseInt)
  N = input[0]
  Q = input[1]
var
  board = newSeqWith(N+1, 0)
for _ in 0..<Q:
  let query = stdin.readline.split.map(parseInt)
  board[query[0]-1].inc
  board[query[1]].dec
for i in 0..<N:
  board[i+1] += board[i]
  stdout.write(board[i] mod 2)
echo()
