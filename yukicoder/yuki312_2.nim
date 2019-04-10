import strutils, algorithm
let N = stdin.readline.parseBiggestInt
var
  list: seq[int64] = @[]
  i = 1.int64
while i * i <= N:
  if N mod i == 0:
    list.add(i)
    if i * i != N:
      list.add(N div i)
list.sort(cmp[int64])
for l in list:
  if l >= 3:
    echo(l)
    break
