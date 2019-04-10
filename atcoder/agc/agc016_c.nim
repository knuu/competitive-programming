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
  for i in 0..<H:
    var row = newSeq[string]()
    for j in 0..<W:
      if i mod h == 0 and j mod w == 0:
        row.add("250")
      elif i mod h == h - 1 and j mod w == w - 1:
        row.add("-251")
      else:
        row.add("0")
    row.join(" ").echo
