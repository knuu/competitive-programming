import strutils, sequtils

let T = stdin.readline.parseInt

for t in 1..T:
  var
    N = stdin.readline
    i = 1
  while i < N.len:
    let (p, n) = (N[i-1].ord, N[i].ord)
    if p > n:
      N[i-1] = (p-1).chr
      for j in i..<N.len:
        N[j] = '9'
      if i > 1:
        i -= 2
    i.inc
  echo("Case #", t, ": ", N.parseBiggestInt)
