# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

var
  S: string
  counter: seq[seq[int]]

proc check(cand_s: string): bool =
  var idx = -1
  for s in cand_s:
    let
      ord_s = s.ord - 'a'.ord
      next_idx = counter[ord_s].lowerBound(idx + 1)
    if next_idx == counter[ord_s].len:
      cand_s.echo
      return true
    else:
      idx = counter[ord_s][next_idx]
  return false

proc dfs(s_len: int, tmp_s: string): bool =
  if tmp_s.len == s_len:
    return check(tmp_s)
  else:
    for i in 0..25:
      if dfs(s_len, tmp_s & ('a'.ord + i).char):
        return true
    return false

when isMainModule:
  S = getLine
  counter = newSeqWith(26, newSeq[int]())
  for i, s in S:
    counter[s.ord - 'a'.ord].add(i)
  for i in 1..5:
    if dfs(i, ""):
      break
