import strutils, sequtils
let
  N = stdin.readline.parseInt
  A = stdin.readline.split.map(parseInt)
var ans = 0
for i in 0..<(N-2):
  let kado = @[A[i], A[i+1], A[i+2]]
  if @[0, 1, 2].allIt(kado[it] != kado[(it+1) mod 3]) and (kado.max == kado[1] or kado.min == kado[1]):
    ans.inc
ans.echo
