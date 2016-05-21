import strutils, sequtils
let
  V = stdin.readline.parseInt
  m = (1e9.int + 7).int64
var
  edge: seq[seq[int]] = newSeqWith(V, newSeq[int](0))
  dp: seq[seq[int64]] = newSeqWith(V, newSeqWith(2, -1.int64))
for _ in 0..<V-1:
  let e = stdin.readline.split.mapIt(it.parseInt-1)
  edge[e[0]].add(e[1])
  edge[e[1]].add(e[0])

proc dfs(v, par, par_c: int): int64 =
  if dp[v][par_c] != -1: return dp[v][par_c]
  if v > 0 and edge[v].len == 1:
    return 1
  result = 1.int64
  for c in edge[v]:
    if c != par:
      var ret = 0.int64
      if par_c == 0:
        ret += dfs(c, v, 1)
      ret += dfs(c, v, 0)
      result *= ret mod m
      result = result mod m
  dp[v][par_c] = result
echo((dfs(0, -1, 0) + dfs(0, -1, 1)) mod m)
