import strutils, sequtils
let
  t = stdin.readline.split.map(parseInt)
  (sx, sy, tx, ty) = (t[0], t[1], t[2], t[3])
  W = tx - sx
  H = ty - sy
echo(repeat('U', H), repeat('R', W), repeat('D', H), repeat('L', W + 1),
     repeat('U', H + 1), repeat('R', W + 1), 'D', 'R', repeat('D', H + 1),
     repeat('L', W + 1), 'U')
