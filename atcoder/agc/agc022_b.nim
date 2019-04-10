# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  var N = getInteger
  if N == 3:
    echo("2 3 25")
    quit()
  var
    even = @[2, 4]
    odd = @[3, 9]
  N -= 4
  while N > 1 and odd[^1] + 12 < 30000:
    odd.add(odd[^1] + 6)
    odd.add(odd[^1] + 6)
    N -= 2
  while N > 0:
    even.add(even[^1] + 2)
    N.dec
  if even.sum mod 3 != 0:
    discard odd.pop
    discard odd.pop
    even.add(even[^1] + 2)
    even.add(even[^1] + 2)
  for i, x in odd:
    if i > 0:
      stdout.write(' ')
    stdout.write(x)
  for x in even:
    stdout.write(' ')
    stdout.write(x)
  echo()
