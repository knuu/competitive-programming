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
    (A, B, C, D, E, F) = (tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5])
  var water, sugar = newSeqWith(F + 1, false)
  water[0] = true
  sugar[0] = true
  for i in 0..F:
    if water[i] and i + 100 * A <= F:
      water[i + 100 * A] = true
    if water[i] and i + 100 * B <= F:
      water[i + 100 * B] = true
    if sugar[i] and i + C <= F:
      sugar[i + C] = true
    if sugar[i] and i + D <= F:
      sugar[i + D] = true
  var
    ans_weight = 1
    ans_sugar = 0
  for i in 0..F:
    for j in 0..F:
      if i + j <= F and water[i] and sugar[j] and j * (100 + E) <= (i + j) * E and ans_sugar * (i + j) <= ans_weight * j:
        ans_sugar = j
        ans_weight = i + j
  echo(ans_weight, ' ', ans_sugar)
