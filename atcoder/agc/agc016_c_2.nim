# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let tmp = getIntSeq
  var (H, W, h, w) = (tmp[0], tmp[1], tmp[2], tmp[3])
  if H mod h == 0 and W mod w == 0:
    echo("No")
    quit()
  else:
    echo("Yes")
  var flag = false
  if W mod w == 0:
    flag = true
    swap(H, W)
    swap(h, w)
  var acc_row = newSeq[int](W + 1)
  acc_row[^1] = 1
  for i in countdown(W, W - w, 1):
    for j in countdown(i - w, 0, w):
      acc_row[j] = acc_row[j + w] + 1
  acc_row[0] = 0
  for i in countup(w, W, w):
    acc_row[i] = acc_row[i - w] - 1

  let row = (0..<W).mapIt(acc_row[it + 1] - acc_row[it])

  if not flag:
    for _ in 0..<H:
      row.mapIt(it.intToStr).join(" ").echo
  else:
    for c in row:
      c.repeat(H).mapIt(it.intToStr).join(" ").echo
  if row.sum <= 0 or (0..<W-w+1).anyIt(row[it..<it+w].sum >= 0):
    quit(-1)
