import strutils, sets

let N = stdin.readline.parseBiggestInt

var
  i = 1.int64
  Ps = initSet[string]()

while i * i <= N:
  if N mod i == 0:
    Ps.incl([i, N div i].join)
    Ps.incl([N div i, i].join)
  i.inc
Ps.len.echo
