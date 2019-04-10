# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

const MOD = 1e9.int64 + 7

proc sum_all(arr: seq[int64]): int64 =
  let L = arr.len
  var diff = newSeq[int64](L)
  for i in 1..<L:
    diff[i] = arr[i] - arr[i - 1]
  for i in 1..<L:
    diff[i] = (diff[i] + diff[i - 1]) mod MOD
  var acc_sum = 0.int64
  for i in countdown(L - 1, 1):
    acc_sum = (acc_sum + diff[i]) mod MOD
    result = (result + acc_sum + (MOD - diff[i - 1]) * (L - i.int64) mod MOD) mod MOD
  return result

when isMainModule:
  let
    tmp = getIntSeq
    (N, M) = (tmp[0], tmp[1])
    X = getBigIntSeq
    Y = getBigIntSeq
  (sum_all(X) * sum_all(Y) mod MOD).echo
