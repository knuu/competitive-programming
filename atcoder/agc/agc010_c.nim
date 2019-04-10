# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

var
  edge: seq[seq[int]]
  A: seq[int64]

proc dfs(v, par: int): int64 =
  if par != -1 and edge[v].len == 1:
    return A[v]

  var max_path, sum_path = 0.int64

  for c in edge[v]:
    if c != par:
      var path = dfs(c, v)
      if path == -1:
        return -1
      sum_path += path
      max_path = max(max_path, path)
  let p_path = 2.int64 * A[v] - sum_path
  if 0 <= p_path and max_path <= A[v] and A[v] <= sum_path:
    return p_path
  else:
    return -1

when isMainModule:
  let
    N = getInteger
  A = getBigIntSeq
  edge = newSeqWith(N, newSeq[int]())
  for _ in 0..<N-1:
    let
      tmp = getIntSeq.mapIt(it-1)
      (a, b) = (tmp[0], tmp[1])
    edge[a].add(b)
    edge[b].add(a)
  let P = dfs(0, -1)
  if edge[0].len == 1:
    echo(if P == A[0]: "YES" else: "NO")
  else:
    echo(if P == 0: "YES" else: "NO")
