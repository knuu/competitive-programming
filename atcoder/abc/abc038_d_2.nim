import strutils, algorithm, sequtils
let N = stdin.readline.parseInt
var boxes: seq[(int, int)] = @[]
for _ in 1..N:
  let t = stdin.readline.split.map(parseInt)
  boxes.add((t[0], -t[1]))
boxes.sort(cmp)
var lis: seq[int] = @[]
for i, box in boxes:
  let
    (_, h) = box
    idx = lis.lowerBound(-h)
  if idx == lis.len:
    lis.add(-h)
  else:
    lis[idx] = min(lis[idx], -h)
lis.len.echo
