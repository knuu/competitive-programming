import strutils, sequtils, strscans

let input = stdin.readline
var C, D: int
discard input.scanf("$i $i", C, D)
var
  flag1, flag2 = 0
  ans = 0.0
if 5 * C <= 2 * D:
  flag1.inc
  ans = max(ans, 7 * C * 2000 / 2)
else:
  flag2.inc
  ans = max(ans, 7 * D * 2000 / 5)

if C <= 3 * D:
  flag1.inc
  ans = max(ans, 4 * C * 1000 / 3)
else:
  flag2.inc
  ans = max(ans, (4 * D * 1000).float)

if max(flag1, flag2) < 2:
  ans = max(ans, 1000 * (20 * C - 8 * D) / 13 - 2000 * 7 * (C - 3 * D) / 13)
ans.echo
