import strutils, sequtils, math
let
  t = stdin.readline.split.mapIt(it.parseInt.abs)
  (x, y, r) = (t[0], t[1], t[2])
for i in countdown(342, 0):
  if (x + y - i) * (x + y - i) <= r * r * 2:
    echo(i + 1)
    quit()
