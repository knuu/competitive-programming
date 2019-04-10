import strutils, sequtils, sets

let
  tmp = stdin.readline.split.map(parseInt)
  (H, W, N) = (tmp[0], tmp[1], tmp[2])
var
  notp = initSet[(int, int, int)]()
let drc = @[@[(-1, 0), (0, 0)], @[(0, -1), (0, 0)]]
proc in_board(r, c, i: int): bool =
  if i == 0:
    return 0 <= r and r < H-1 and 0 <= c and c < W
  else:
    return 0 <= r and r < H and 0 <= c and c < W-1

for _ in 0..<N:
  let
    v = stdin.readline.split.mapIt(it.parseInt-1)
    (r, c) = (v[0], v[1])
  for i in 0..1:
    for d in drc[i]:
      let
        (dr, dc) = d
        (nr, nc) = (r + dr, c + dc)
      if in_board(nr, nc, i):
        notp.incl((i, nr, nc))
echo(H.int64 * (W - 1).int64 + (H - 1).int64 * W.int64 - notp.len.int64)
