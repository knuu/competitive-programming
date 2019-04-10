import strutils, sequtils, math

let
  N = stdin.readline.parseInt
  A = stdin.readline.split.map(parseInt)
  legs = @[2, 4]

for k in 0..1:
  var
    total = A[0] + legs[k]
    kind = newSeqWith(N, -1)
  for i, a in A:
    for j, l in legs:
      if a + l == total:
        kind[i] = j
        break
  if kind.allIt(it != -1) and total == kind.mapIt(legs[it]).sum:
    echo(kind.filterIt(it == 0).len, ' ', kind.filterIt(it == 1).len)
    quit()
