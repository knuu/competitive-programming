import strutils, sequtils

let
  tmp = stdin.readline.split.map(parseInt)
  (N, A, B) = (tmp[0], tmp[1].int64, tmp[2].int64)
var H = newSeq[int64](N)

for i in 0..<N:
  H[i] = stdin.readline.parseBiggestInt

proc check(t: int64): bool =
  var cnt = 0.int64
  for h in H:
    if h > t * B:
      cnt += (h - t * B + (A - B) - 1) div (A - B)
  return cnt <= t

var (left, right) = (0.int64, 1e9.int64)

while left + 1 < right:
  let mid = (left + right) div 2
  if check(mid):
    right = mid
  else:
    left = mid
right.echo
