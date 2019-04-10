import strutils, sequtils, algorithm
let
  N = stdin.readline.parseInt
  A = stdin.readline.split.map(parseInt)
var (left, right) = (-1, N-1)
while left + 1 < right:
  let
    mid = (left + right) div 2
  if A.filterIt(it > mid).isSorted(cmp):
    right = mid
  else:
    left = mid
right.echo
