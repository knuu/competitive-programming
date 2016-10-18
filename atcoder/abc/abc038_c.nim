import strutils, sequtils
let N = stdin.readline.parseInt
var
  A = stdin.readline.split.map(parseInt)
  left, ans = 0.int64
A.add(0)

while left < N:
  var right = left + 1
  while A[right.int-1] < A[right.int]: right.inc
  ans += (right - left) * (right - left + 1) div 2
  left = right
ans.echo
