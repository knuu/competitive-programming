import strutils, algorithm, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, L) = (tmp[0], tmp[1])
var S = newSeq[string](N)

for i in 0..<N:
  S[i] = stdin.readline
S.sorted(cmp).join("").echo
