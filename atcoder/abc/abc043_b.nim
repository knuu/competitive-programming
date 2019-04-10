import strutils
let S = stdin.readline
var screen = ""

for s in S:
  if s == 'B' and screen != "":
    screen = screen[0..<(^1)]
  elif s in "01":
    screen.add(s)
screen.echo
