import strutils, sequtils, queues, algorithm

let
  tmp1 = stdin.readline.split.map(parseInt)
  (h, w) = (tmp1[0], tmp1[1])
  tmp2 = stdin.readline.split.mapIt(it.parseInt-1)
  (sr, sc, gr, gc) = (tmp2[0], tmp2[1], tmp2[2], tmp2[3])
var board = newSeq[string](h)

for i in 0..<h:
  board[i] = stdin.readline

var
  used = newSeqWith(h, newSeqWith(w, false))
  que = initQueue[(int, int)]()

que.enqueue((sr, sc))

let drc = [(-1, 0), (0, 1), (1, 0), (0, -1)]

proc in_board(r, c: int): bool =
  return 0 <= r and r < h and 0 <= c and c < w

while que.len > 0:
  let (r, c) = que.dequeue
  if used[r][c]:
    continue
  used[r][c] = true
  if (r, c) == (gr, gc):
    echo("YES")
    quit(0)
  for d in drc:
    let
      (dr, dc) = d
      (nr, nc) = (r+dr, c+dc)
      (nnr, nnc) = (r+2*dr, c+2*dc)
    if in_board(nr, nc) and not used[nr][nc] and abs(board[nr][nc].int - board[r][c].int) <= 1:
      que.enqueue((nr, nc))
    if in_board(nnr, nnc) and not used[nnr][nnc] and board[nnr][nnc] == board[r][c] and board[r][c] >= board[nr][nc]:
      que.enqueue((nnr, nnc))
echo("NO")
