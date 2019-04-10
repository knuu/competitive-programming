import sequtils, strutils

let
  input = stdin.readline.split.map(parseInt)
  (N, K) = (input[0], input[1])
  A = stdin.readline.split.mapIt(it.parseInt-1)
var
  ans = 0
  edge = newSeqWith(N, newSeq[int]())

for i, a in A[1..<N]:
  edge[a].add(i+1)

if A[0] != 0: ans.inc

proc dfs(v, p: int): int {.discardable.} =
  result = 0
  for c in edge[v]:
    result = max(result, dfs(c, v) + 1)
  if result == K-1 and p != 0:
    result = -1
    ans.inc
dfs(0, 0)
ans.echo
