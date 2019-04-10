import strutils, sequtils, algorithm
let N = stdin.readline.parseInt
var
  A = stdin.readline.split.map(parseBiggestInt)
  accA = A
A.sort(cmp)
accA.sort(cmp)
for i in 0..<(N-1):
  accA[i+1] += accA[i]
var cnt = 1
for i in countDown(N-2, 0):
  if A[i+1] <= 2 * accA[i]:
    cnt.inc
  else:
    break
cnt.echo
