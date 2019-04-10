import strutils, sequtils, math
let
  input = stdin.readline.split.map(parseInt)
  (N, Q) = (input[0], input[1])
var cones = newSeq[seq[int]](N)
for i in 0..<N:
  cones[i] = stdin.readline.split.map(parseInt)
var accum = newSeqWith(3*1e4.int, 0.0)
for i in 0..<(3*1e4.int):
  for cone in cones:
    let
      (x, r, h) = (cone[0], cone[1], cone[2])
      V = PI * pow(r.float, 2) * h.float / 3.0
    if x + h <= i:
      accum[i] += V
    elif x <= i:
      accum[i] += V * (pow(h.float, 3) - pow((x + h - i).float, 3)) / pow(h.float, 3)

for i in 0..<Q:
  let
    input = stdin.readline.split.map(parseInt)
    (A, B) = (input[0], input[1])
  (accum[B] - accum[A]).formatFloat(precision = 32).echo
