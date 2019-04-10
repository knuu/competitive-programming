# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

type
  StronglyConnectedComponents = object
    graph, rev_graph: seq[seq[int]]
    vs, comp, sorted_vs: seq[int]
    used: seq[bool]

proc initSCC(size: int): StronglyConnectedComponents =
  assert size > 0
  return StronglyConnectedComponents(
    graph: newSeqWith(size, newSeq[int]()),
    rev_graph: newSeqWith(size, newSeq[int]()),
    vs: newSeq[int](),
    comp: newSeq[int](size),
    sorted_vs: newSeq[int](size),
    used: newSeq[bool](size)
  )

proc add_edge(scc: var StronglyConnectedComponents, v1: int, v2: int) =
  scc.graph[v1].add(v2)
  scc.rev_graph[v2].add(v1)

proc dfs(scc: var StronglyConnectedComponents, v: int) =
  scc.used[v] = true
  for c in scc.graph[v]:
    if not scc.used[c]:
      scc.dfs(c)
  scc.vs.add(v)

proc rev_dfs(scc: var StronglyConnectedComponents, v: int, k: int) =
  scc.used[v] = true
  scc.comp[v] = k
  for c in scc.rev_graph[v]:
    if (not scc.used[c]):
      scc.rev_dfs(c, k)

proc run(scc: var StronglyConnectedComponents): int =
  scc.used.fill(false)
  for v in 0..<scc.graph.len:
    if not scc.used[v]:
      scc.dfs(v)
  scc.used.fill(false)
  var k = 0
  for v in scc.vs.reversed:
    if not scc.used[v]:
      scc.rev_dfs(v, k)
      k.inc
  for i, v in scc.comp:
    scc.sorted_vs[v] = i
  return k

when isMainModule:
  let
    tmp = getIntSeq
    (N, M) = (tmp[0], tmp[1])
  var scc = initSCC(N)
  for i in 0..<M:
    let e = getIntSeq
    scc.add_edge(e[0] - 1, e[1] - 1)
  discard scc.run
  var
    dp = newSeq[int](N)

  for v in scc.sorted_vs:
    for c in scc.graph[v]:
      dp[c] = max(dp[c], dp[v] + 1)
  dp.max.echo
