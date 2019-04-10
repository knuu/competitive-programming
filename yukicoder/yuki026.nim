{.checks: off, optimization: speed.}
import strutils, sequtils
var N = stdin.readline.parseInt
for _ in 0..<stdin.readline.parseInt:
  let t = stdin.readline.split.map(parseInt)
  for i in 0..1:
    if t[i] == N:
      N = t[i xor 1]
      break
N.echo
