import strutils
let N = stdin.readline.parseInt
var board: seq[string] = @[]
for _ in 0..<N:
  board.add(stdin.readline)
for i in 0..<N:
  for j in countdown(N-1, 0):
    stdout.write(board[j][i])
  echo()
