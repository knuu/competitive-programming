import strutils, sequtils, queues
let drc = [(-1, 0), (0, 1), (1, 0), (0, -1)]
var
  tmp1 = stdin.readline.split.map(parseInt)
  (R, C) = (tmp1[0], tmp1[1])
  tmp2 = stdin.readline.split.mapIt(it.parseInt-1)
  (sr, sc) = (tmp2[0], tmp2[1])
  tmp3 = stdin.readline.split.mapIt(it.parseInt-1)
  (gr, gc) = (tmp3[0], tmp3[1])
  board: seq[string] = @[]
  que = initQueue[(int, int, int)]()
for _ in 0..<R: board.add(stdin.readline)
que.add((sr, sc, 0))
while que.len > 0:
  let (r, c, cnt) = que.dequeue
  if (r, c) == (gr, gc):
    echo(cnt)
    break
  elif board[r][c] == 'x':
    continue
  board[r][c] = 'x'
  for d in drc:
    let
      (dr, dc) = d
      (nr, nc) = (r+dr, c+dc)
    if 0 <= nr and nr < R and 0 <= nc and nc < C and board[nr][nc] == '.':
      que.add((nr, nc, cnt+1))
