import strutils, sequtils
let N = stdin.readline
var cand = newSeq[string]()
for i in 0..<N.len:
  for j in 0..<N.len:
    var c = N
    swap(c[i], c[j])
    cand.add(c)
cand.map(parseInt).max.echo
