import sets, sequtils, math, strutils
let S = stdin.readline.strip
var a = initSet[string]()
for i in 0..<S.len:
  for j in i..<S.len:
    a.incl(S[i..j])
echo(a.mapIt(it.len.int64).sum)
echo(a)
