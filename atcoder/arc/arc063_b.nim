import strutils, sequtils, algorithm
let
  input = stdin.readline.split.map(parseInt)
  (N, T) = (input[0], input[1])
var
  A = stdin.readline.split.map(parseInt)
  now = 0
for i in countdown(N-1, 0):
  now = max(now, A[i])
  A[i] = now - A[i]
A.sort(cmp)
A.filterIt(it == A[^1]).len.echo
