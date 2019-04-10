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
    (N, K, Q) = (tmp[0], tmp[1], tmp[2])
    A = getIntSeq
  var ans = 1e9.int
  for i, a in A:
    var arr, cand = newSeq[int]()
    var left = 0
    var flag = true
    for j, x in A:
      if x >= a:
        arr.add(x)
      else:
        if arr.len >= K:
          arr.sort(cmp)
          arr.reverse
          while arr.len >= K:
            cand.add(arr.pop)
        elif left <= i and i < j:
          flag = false
          break
        arr = newSeq[int]()
        left = j + 1

    arr.sort(cmp)
    arr.reverse
    while arr.len >= K:
      cand.add(arr.pop)
    cand.sort(cmp)
    if flag and cand.len >= Q:
      ans = min(ans, cand[Q - 1] - cand[0])
  ans.echo
