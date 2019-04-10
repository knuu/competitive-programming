import strutils, sequtils, algorithm

let
  tmp = stdin.readline.split.map(parseInt)
  (N, C, K) = (tmp[0], tmp[1], tmp[2])

var T = newSeq[int](N)
for i in 0..<N: T[i] = stdin.readline.parseInt
T.sort(cmp)

var ans, idx = 0
while idx < N:
  let start = T[idx]
  ans.inc
  var cnt = 0
  while idx < N and cnt < C and T[idx] <= start + K:
    idx.inc
    cnt.inc
ans.echo
