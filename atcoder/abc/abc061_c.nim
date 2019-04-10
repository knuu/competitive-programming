import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, K) = (tmp[0], tmp[1].int64)
var counter = newSeq[int64](1e5.int + 1)

for _ in 1..N:
  let
    tmp = stdin.readline.split.map(parseInt)
    (a, b) = (tmp[0], tmp[1].int64)
  counter[a] += b

var acc = 0.int64
for i in 0..1e5.int:
  acc += counter[i]
  if acc >= K:
    echo(i)
    break
