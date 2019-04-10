import strutils
let S = stdin.readline
for i in countDown(99, 0):
  if i.intToStr in S:
    echo(i)
    break
