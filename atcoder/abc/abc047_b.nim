import strutils, sequtils

let
  t1 = stdin.readline.split.map(parseInt)
  (W, H, N) = (t1[0], t1[1], t1[2])
var
  x0, y0 = 0
  x1 = W
  y1 = H

for _ in 0..<N:
  let
    t2 = stdin.readline.split.map(parseInt)
    (x, y, a) = (t2[0], t2[1], t2[2])
  if a == 1:
    x0 = max(x0, x)
  elif a == 2:
    x1 = min(x1, x)
  elif a == 3:
    y0 = max(y0, y)
  else:
    y1 = min(y1, y)
echo(max(0, x1 - x0) * max(0, y1 - y0))
