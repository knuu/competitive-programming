# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc dfs(v: int, color: var seq[int], edge: var seq[seq[int]]): (bool, int, int) =
  var
    is_ok = true
    pos, neg = 0
  if color[v] == 1:
    pos.inc
  else:
    neg.inc
  for c in edge[v]:
    if color[c] == 0:
      color[c] = -color[v]
      let (flag, p, n) = dfs(c, color, edge)
      is_ok = flag and is_ok
      pos += p
      neg += n
    if color[c] != 0 and color[c] != -color[v]:
      is_ok = false
  return (is_ok, pos, neg)

when isMainModule:
  let
    tmp = getIntSeq
    (N, M) = (tmp[0], tmp[1])
  var co_edges = initSet[(int, int)]()
  for i in 0..<M:
    let
      tmp = getIntSeq
      (s, t) = (tmp[0] - 1, tmp[1] - 1)
    co_edges.incl(if s < t: (s, t) else: (t, s))
  var edges = newSeqWith(N, newSeq[int]())
  for i in 0..<N:
    for j in (i + 1)..<N:
      if not co_edges.contains((i, j)):
        edges[i].add(j)
        edges[j].add(i)
  var bi_graphs = newSeq[(int, int)]()
  var color = newSeq[int](N)
  for i in 0..<N:
    if color[i] == 0:
      color[i] = 1
      let (flag, pos, neg) = dfs(i, color, edges)
      if not flag:
        echo(-1)
        quit()
      bi_graphs.add((pos, neg))
  var dp = newSeqWith(N + 1, false)
  dp[0] = true
  for g in bi_graphs:
    let (s, t) = g
    var dp_tmp = newSeqWith(N + 1, false)
    for i in 0..N:
      if not dp[i]:
        continue
      if i + s <= N:
        dp_tmp[i + s] = true
      if i + t <= N:
        dp_tmp[i + t] = true
    dp = dp_tmp

  var ans = N * (N - 1) div 2
  for i in 0..N:
    if dp[i]:
      ans = min(ans, i * (i - 1) div 2 + (N - i) * (N - i - 1) div 2)
  ans.echo
