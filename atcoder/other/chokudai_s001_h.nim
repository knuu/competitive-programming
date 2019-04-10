import strutils, sequtils, algorithm

discard stdin.readline
let A = stdin.readline.split.map(parseInt)
var lis = newSeq[int](0)

for a in A:
  let idx = lis.lowerBound(a)
  if lis.len == idx:
    lis.add(a)
  else:
    lis[idx] = a
lis.len.echo
