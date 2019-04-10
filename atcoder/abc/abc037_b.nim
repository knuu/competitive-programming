import sequtils, strutils, algorithm
let
  input = stdin.readline.split.map(parseInt)
  (N, Q) = (input[0], input[1])
var A = newSeqWith(N, 0)
for _ in 0..<Q:
  let
    t2 = stdin.readline.split.map(parseInt)
    (L, R, T) = (t2[0]-1, t2[1]-1, t2[2])
  for i in L..R:
    A[i] = T
for a in A:
  echo(a)
