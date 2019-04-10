import strutils, sequtils, math
let
  N = stdin.readline.parseInt
  T = stdin.readline.split.map(parseInt)
  Tsum = T.sum
  M = stdin.readline.parseInt
for i in 0..<M:
  let d = stdin.readline.split.map(parseInt)
  echo(Tsum - T[d[0] - 1] + d[1])
