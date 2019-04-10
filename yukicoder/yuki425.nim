import strutils, sequtils

var
  tmp = stdin.readline.split.map(parseInt)
  (p, q) = (tmp[0], tmp[1])
  pr = @[@[1/9, 1/9, 1/9],
         @[0.0, 0.0, 0.0]]
  win = 1/3

for _ in range(1000):
