import strutils, sequtils
let
  tmp = stdin.readline.split.map(parseInt)
  (N, M) = (tmp[0], tmp[1])
var edge = newSeqWith(N, newSeq[int]())
for _ in 1..M:
  let
    e = stdin.readline.split.map(parseInt)
    (s, t) = (e[0]-1, e[1]-1)
  edge[t].add(s)

var dp = newSeq[int64](1 shl N)
dp[0] = 1
for state in 0..<(1 shl N):
  for v in 0..<N:
    if (state shr v and 1) == 0 and edge[v].allIt((state shr it and 1) == 1):
      dp[state or (1 shl v)] += dp[state]
dp[(1 shl N) - 1].echo
