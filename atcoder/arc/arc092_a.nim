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
  var
    red = newSeq[(int, int)](N)
    blue = newSeq[(int, int)](N)
  for i in 0..<N:
    let
      tmp = getIntSeq
      (a, b) = (tmp[0], tmp[1])
    red[i] = (a, b)
  for i in 0..<N:
    let
      tmp = getIntSeq
      (c, d) = (tmp[0], tmp[1])
    blue[i] = (c, d)
  blue.sort(cmp)
  var
    ans = 0
    used = newSeqWith(N, false)
  for j, b_tmp in blue:
    let (c, d) = b_tmp
    var
      cand_y = -1
      cand = -1
    for i, r_tmp in red:
      if used[i]:
        continue
      let (a, b) = r_tmp
      if a < c and b < d and b > cand_y:
        cand_y = b
        cand = i
    if cand != -1:
      ans.inc
      used[cand] = true
  ans.echo
