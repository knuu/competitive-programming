{.checks: off, optimization: speed.}
import strutils, sequtils, sets, algorithm

let
  t1 = stdin.readline.split.map(parseInt)
  (N, M, Q) = (t1[0], t1[1], t1[2])
var edges, query = newSeq[(int, int)]()
for i in 0..<M:
  let t = stdin.readline.split.map(parseInt)
  edges.add((t[0] - 1, t[1] - 1))
for i in 0..<Q:
  let t = stdin.readline.split.map(parseInt)
  query.add((t[0] - 1, t[1] - 1))
let query_set = toSet(query)

var graph = newSeqWith(N, newSeq[int]())
for e in edges:
  if not query_set.contains(e):
    let (s, t) = e
    graph[s].add(t)
    graph[t].add(s)
var used = newSeq[int](N)

proc dfs(v, cnt: int) =
  if used[v] != 0:
    return
  used[v] = cnt
  for c in graph[v]:
    dfs(c, cnt)

dfs(0, -1)
query.reverse
for i, q in query:
  let (s, t) = q
  graph[s].add(t)
  graph[t].add(s)
  if used[s] != 0 or used[t] != 0:
    dfs(s, Q-i)
    dfs(t, Q-i)
used[1..<N].mapIt(it.intToStr).join("\n").echo
