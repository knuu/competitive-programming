import strutils, algorithm
let N = stdin.readline.parseBiggestInt
var
  list: seq[int64] = @[]
  i = 1.int64
while i * i <= N:
  if N mod i == 0.int64:
    list.add(i)
    if i * i != N:
      list.add(N div i)
  i.inc
list.sort(cmp[int64])
for n in list:
  if n >= 3.int64:
    echo(n)
    break
