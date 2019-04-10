import strutils, sequtils
let N = stdin.readline.parseInt
var cnts = newSeq[int](2)
for x in stdin.readline.split.map(parseInt):
  cnts[x.abs mod 2].inc
echo(abs(cnts[0] - cnts[1]))
