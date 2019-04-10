import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, M) = (tmp[0], tmp[1])
var counter = newSeq[int](N)

for _ in 0..<M:
  let
    tmp = stdin.readline.split.mapIt(it.parseInt-1)
    (a, b) = (tmp[0], tmp[1])
  counter[a].inc
  counter[b].inc
for c in counter:
  c.echo
