import strutils, sequtils, algorithm, math
let
  t = stdin.readline.split.map(parseInt)
  (N, K) = (t[0], t[1])
  A = stdin.readline.split.map(parseBiggestInt)
var
  ans, s = A[0..<K].sum
for i in 0..<N-K:
  s += A[i+K] - A[i]
  ans += s
ans.echo
