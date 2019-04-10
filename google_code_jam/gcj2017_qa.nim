import strutils, sequtils
let T = stdin.readline.parseInt

for t in 1..T:
  var
    line = stdin.readline.split
    (S, K) = (line[0], line[1].parseInt)
    cnt = 0
  for i in 0..(S.len-K):
    if S[i] == '-':
      for j in i..<(i+K):
        S[j] = "+-"[(S[j] == '+').int]
      cnt.inc
  if S.count("-") == 0:
    echo("Case #", t, ": ", cnt)
  else:
    echo("Case #", t, ": IMPOSSIBLE")
