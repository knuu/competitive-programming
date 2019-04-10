# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

let MOD = 1e9.int64 + 7

proc dfs(v: int, p: int, edge: seq[seq[int]]): (int64, int64) =
  var (white, black) = (1.int64, 1.int64)
  for c in edge[v]:
    if c != p:
      let (w, b) = dfs(c, v, edge)
      white = (white * (w + b)) mod MOD
      black = (black * w) mod MOD
  return (white, black)


when isMainModule:
  let
    N = getInteger
  var edge = newSeqWith(N, newSeq[int]())
  for i in 0..<(N - 1):
    let
      e = getIntSeq
      (s, t) = (e[0] - 1, e[1] - 1)
    edge[s].add(t)
    edge[t].add(s)
  let (white, black) = dfs(0, -1, edge)
  echo((white + black) mod MOD)
