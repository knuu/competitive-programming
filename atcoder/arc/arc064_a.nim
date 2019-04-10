import strutils, sequtils

let
  input = stdin.readline.split.map(parseInt)
  (N, x) = (input[0], input[1].int64)

var
  A = stdin.readline.split.map(parseBiggestInt)
  ans = 0.int64

let res = max(0.int64, A[0] - x)
ans += res
A[0] -= res

for i, a in A[0..<(N-1)]:
  let res = max(0.int64, A[i] + A[i+1] - x)
  A[i+1] -= res
  ans += res
  assert(A[i+1] >= 0)
ans.echo
