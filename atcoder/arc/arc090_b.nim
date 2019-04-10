# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    tmp = getIntSeq
    (N, M) = (tmp[0], tmp[1])
  var in_edge, out_edge = newSeqWith(N, newSeq[(int, int)]())
  for i in 0..<M:
    let
      e = getIntSeq
      (l, r, d) = (e[0] - 1, e[1] - 1, e[2])
    in_edge[l].add((r, d))
    out_edge[r].add((l, d))

  let INF = 1e9.int + 1
  var dist = newSeqWith(N, INF)

  for i in 0..<N:
    if dist[i] == INF:
      var que = initQueue[(int, int)]()
      que.add((i, 0))
      while que.len > 0:
        let (v, d) = que.dequeue
        if dist[v] != INF:
          if dist[v] != d:
            echo("No")
            quit()
          else:
            continue
        dist[v] = d
        for e in in_edge[v]:
          let (nv, nd) = e
          if dist[nv] != INF and dist[nv] != d - nd:
            echo("No")
            quit()
          elif dist[nv] == INF:
            que.add((nv, d - nd))
        for e in out_edge[v]:
          let (nv, nd) = e
          if dist[nv] != INF and dist[nv] != d + nd:
            echo("No")
            quit()
          elif dist[nv] == INF:
            que.add((nv, d + nd))
  echo("Yes")
