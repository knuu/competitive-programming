# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    tmp = getBigIntSeq
    (N, X) = (tmp[0], tmp[1])

  var
    ans = 0.int64
    res = X

  for i in countdown(N, 0):
    let
      b_i = (1.int64 shl (i + 2)) - 3
      b_ii = (1.int64 shl (i + 1)) - 3
      p_i = (1.int64 shl (i + 1)) - 1
      p_ii = (1.int64 shl i) - 1
    if res == 1:
      ans += (i == 0).int64
      break
    elif res <= 1 + b_ii:
      res -= 1
    elif res == 2 + b_ii:
      ans += 1 + p_ii
      break
    elif res < b_i:
      ans += 1 + p_ii
      res -= 2 + b_ii
    else:
      ans += p_i
      break
  ans.echo
