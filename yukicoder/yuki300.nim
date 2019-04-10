import strutils, math, tables
var
  X = stdin.readline.parseBiggestInt
  ans = 1.int64

for i in 2..X.float.sqrt.int+1:
  if X mod i.int64 == 0:
    var cnt = 0
    while X mod i.int64 == 0:
      cnt.inc
      X = X div i.int64
    if cnt mod 2 == 1:
      ans *= i.int64
if X > 1:
  ans *= X
echo(ans)
