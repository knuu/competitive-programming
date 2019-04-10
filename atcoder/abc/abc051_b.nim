import strutils, sequtils
let
  t = stdin.readline.split.map(parseInt)
  (K, S) = (t[0], t[1])
var ans = 0
for x in 0..K:
  for y in 0..K:
    let z = S - x - y
    if 0 <= z and z <= K:
      ans.inc
ans.echo
