import strutils, sequtils
let
  S = stdin.readline
  T = stdin.readline.parseInt
var row, col, unknown = 0

for s in S:
  if s == 'U':
    row.inc
  elif s == 'D':
    row.dec
  elif s == 'R':
    col.inc
  elif s == 'L':
    col.dec
  else:
    unknown.inc
let m = row.abs + col.abs
if T == 1:
  echo(m + unknown)
else:
  if m > unknown:
    echo(m - unknown)
  elif (unknown - m) mod 2 == 0:
    echo(0)
  else:
    echo(1)
