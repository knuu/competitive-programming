# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc popcount[T: int64|int](a: T): cint {. importc: "__builtin_popcountl", nodecl, nosideeffect.}

when isMainModule:
  let
    G = getIntSeq
    (N, M) = (G[0], G[1])
  var adj = newSeqWith(N, newSeqWith(N, 0))
  for i in 0..<M:
    let
      e = getIntSeq
      (a, b) = (e[0] - 1, e[1] - 1)
    adj[a][b] = 1
    adj[b][a] = 1
  let (V1, V2) = (N div 2, N - N div 2)

  var ok = newSeqWith(1 shl V1, true)
  for i in 0..<V1:
    for j in (i + 1)..<V1:
      if adj[i][j] == 1:
        ok[(1 shl i) or (1 shl j)] = false
  for state in 0..<(1 shl V1):
    if not ok[state]:
      for i in 0..<V1:
        if (state shr i and 1) == 0:
          ok[state or (1 shl i)] = false

  var notconn = newSeq[int](1 shl V1)
  notconn[0] = (1 shl V2) - 1
  for i in 0..<V1:
    for j in V1..<N:
      if adj[i][j] == 0:
        notconn[1 shl i] = notconn[1 shl i] or (1 shl (j - V1))
  for state in 0..<(1 shl V1):
    for i in 0..<V1:
      if (state shr i and 1) == 0:
        notconn[state or (1 shl i)] = notconn[state] and notconn[1 shl i]

  var indep = newSeqWith(1 shl V2, 1)
  for i in V1..<N:
    for j in i..<N:
      if adj[i][j] == 1:
        indep[(1 shl (i - V1)) or (1 shl (j - V1))] = 0
  for state in 0..<(1 shl V2):
    if indep[state] == 0:
      for i in 0..<V2:
        if (state shr i and 1) == 0:
          indep[state or (1 shl i)] = 0
  for state in 0..<(1 shl V2):
    if indep[state] == 1:
      indep[state] = state.popcount

  for state in 0..<(1 shl V2):
    for i in 0..<V2:
      if (state shr i and 1) == 0:
        indep[state or (1 shl i)] = indep[state or (1 shl i)].max(indep[state])


  var ans = 0
  for state in 0..<(1 shl V1):
    if ok[state]:
      ans = ans.max(state.popcount + indep[notconn[state]])
  ans.echo
