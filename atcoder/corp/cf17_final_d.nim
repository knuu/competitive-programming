# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    N = getInteger
    inf = 2e9.int + 1
  var people = newSeq[(int, int, int)](N)
  for i in 0..<N:
    let tmp = getIntSeq
    people[i] = (tmp[0] + tmp[1], tmp[0], tmp[1])
  people.sort(cmp)

  var
    dp = newSeqWith(2, newSeqWith(N + 1, inf))
    ans = 0
  dp[0][0] = 0
  for i, person in people:
    let (now, next) = (i mod 2, (i + 1) mod 2)
    dp[next].fill(inf)

    let (hp, h, p) = person
    for j in 0..N:
      if dp[now][j] == inf:
        continue
      if j < N and dp[now][j] <= h:
        dp[next][j + 1] = dp[next][j + 1].min(dp[now][j] + p)
      dp[next][j] = dp[next][j].min(dp[now][j])
  for j in countDown(N, 0):
    for i in 0..1:
      if dp[i][j] != inf:
        echo(j)
        quit()
