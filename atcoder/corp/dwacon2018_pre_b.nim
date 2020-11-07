# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    S = getLine
  var
    ans = 0
    cnt = 0
  for s in S:
    if s == '2':
      cnt += 1
    else:
      cnt -= 1
    if cnt < 0:
      echo(-1)
      quit()
    ans = max(ans, cnt)
  if cnt != 0:
    echo(-1)
  else:
    ans.echo
