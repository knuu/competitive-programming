import strutils, sequtils, sets
let
  W = stdin.readline.parseInt
  H = stdin.readline.parseInt
  N = stdin.readline.parseInt
var S, K = initSet[int]()
for _ in 0..<N:
  let c = stdin.readline.split.map(parseInt)
  S.incl(c[0])
  K.incl(c[1])
echo(S.len * H + K.len * W - S.len * K.len - N)
