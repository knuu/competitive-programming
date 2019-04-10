import strutils, sequtils

let N = stdin.readline.parseInt
var A = 0.int64 & stdin.readline.split.map(parseBiggestInt)
for i in 0..<N:
  A[i + 1] += A[i]
var cnt, right = 0
for left in 0..<N:
  while right <= N and A[right] - A[left] < N.int64:
    right.inc
  if right > N:
    break
  if A[right] - A[left] == N.int64:
    cnt.inc
cnt.echo
