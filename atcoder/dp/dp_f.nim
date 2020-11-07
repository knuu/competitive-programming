# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    S = getLine
    T = getLine
  var
    dp = newSeqWith(S.len + 1, newSeq[int](T.len + 1))
    prev = newSeqWith(S.len + 1, newSeq[(int, int)](T.len + 1))

  for i, s in S:
    for j, t in T:
      if s == t:
        dp[i + 1][j + 1] = dp[i][j] + 1
        prev[i + 1][j + 1] = (i, j)
      elif dp[i + 1][j] < dp[i][j + 1]:
        dp[i + 1][j + 1] = dp[i][j + 1]
        prev[i + 1][j + 1] = (i, j + 1)
      else:
        dp[i + 1][j + 1] = dp[i + 1][j]
        prev[i + 1][j + 1] = (i + 1, j)
  var
    now = (S.len, T.len)
    ans = newSeq[char]()
  while now != (0, 0):
    let p = prev[now[0]][now[1]]
    if p[0] == now[0] - 1 and p[1] == now[1] - 1:
      ans.add(S[p[0]])
    now = p
  ans.reverse
  for c in ans:
    stdout.write(c)
