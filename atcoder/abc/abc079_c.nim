# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

when isMainModule:
  let
    N = getLine
  for state in 0..<(1 shl 3):
    var
      ret = N[0].ord - '0'.ord
      ans = @[N[0]]
    for i in 0..<3:
      if (state shr i and 1) == 0:
        ret += N[i + 1].ord - '0'.ord
        ans.add('+')
      else:
        ret -= N[i + 1].ord - '0'.ord
        ans.add('-')
      ans.add(N[i + 1])
    if ret == 7:
      for x in ans:
        stdout.write(x)
      echo("=7")
      quit()
