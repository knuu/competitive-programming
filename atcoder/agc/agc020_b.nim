# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    K = getInteger
    A = getBigIntSeq
  var min_res, max_res = 2.int64
  for a in A.reversed:
    var
      min_a_mul = (min_res + a - 1) div a * a
      max_a_mul = max_res div a * a
    if min_a_mul > max_a_mul:
      echo(-1)
      quit()
    (min_res, max_res) = (min_a_mul, max_a_mul + a - 1)
  echo(min_res, ' ', max_res)
