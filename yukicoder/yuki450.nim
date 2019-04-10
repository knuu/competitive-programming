import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (vl, vr) = (tmp[0], tmp[1])
var d = stdin.readline.parseFloat
let w = stdin.readline.parseInt

var
  t1 = d / (vr + w).float
  t2 = (d - (vl + vr).float * t1) / (vl + w).float
let prev = (t1 + t2) * w.float
d -= (t1 + t2) * (vl + vr).float
t1 = d / (vr + w).float
t2 = (d - (vl + vr).float * t1) / (vl + w).float
let now = (t1 + t2) * w.float

echo(prev / (1 - now / prev))
