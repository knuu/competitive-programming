import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, M, Q) = (tmp[0], tmp[1], tmp[2])
var board = newSeq[string](N)
for i in 0..<N:
  board[i] = stdin.readline

var
  acc_v = newSeqWith(N + 1, newSeqWith(M + 1, 0))
  acc_r = newSeqWith(N, newSeqWith(M + 1, 0))
  acc_c = newSeqWith(N + 1, newSeqWith(M, 0))
for i, row in board:
  for j, col in row:
    if col == '1':
      acc_v[i + 1][j + 1] = 1
    if i < N - 1 and col == '1' and board[i + 1][j] == '1':
      acc_r[i + 1][j + 1] = 1
    if j < M - 1 and col == '1' and row[j + 1] == '1':
      acc_c[i + 1][j + 1] = 1

for i in 0..N:
  for j in 0..<M:
    acc_v[i][j + 1] += acc_v[i][j]
    if i < N:
      acc_r[i][j + 1] += acc_r[i][j]
    if j < M - 1:
      acc_c[i][j + 1] += acc_c[i][j]

for i in 0..<N:
  for j in 0..M:
    acc_v[i + 1][j] += acc_v[i][j]
    if i < N - 1:
      acc_r[i + 1][j] += acc_r[i][j]
    if j < M:
      acc_c[i + 1][j] += acc_c[i][j]

for q in 0..<Q:
  let
    query = stdin.readline.split.map(parseInt)
    (x1, y1, x2, y2) = (query[0] - 1, query[1] - 1, query[2], query[3])
  var ans = acc_v[x2][y2] - acc_v[x1][y2] - acc_v[x2][y1] + acc_v[x1][y1]
  ans -= acc_r[x2-1][y2] - acc_r[x1][y2] - acc_r[x2-1][y1] + acc_r[x1][y1]
  ans -= acc_c[x2][y2-1] - acc_c[x1][y2-1] - acc_c[x2][y1] + acc_c[x1][y1]
  ans.echo
