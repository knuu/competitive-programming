import strutils, sequtils
var
  N = stdin.readline.parseInt
  chokudai: seq[seq[float]] = @[]
for _ in 0..<N:
  chokudai.add(stdin.readline.split.map(parseFloat))
var
  left = -1e5
  right = 1e5
for _ in 0..100:
  var
    mid1 = left + (right - left) / 3
    mid2 = mid1 + (right - left) / 3
    m1, m2 = 0.0
  for p in chokudai:
    m1 = max(m1, abs(p[0] - mid1) * p[2])
    m2 = max(m2, abs(p[0] - mid2) * p[2])
  if m1 > m2:
    left = mid1
  else:
    right = mid2
var
  down = -1e5
  up = 1e5
for _ in 0..100:
  var
    mid1 = down + (up - down) / 3
    mid2 = mid1 + (up - down) / 3
    m1, m2 = 0.0
  for p in chokudai:
    m1 = max(m1, abs(p[1] - mid1) * p[2])
    m2 = max(m2, abs(p[1] - mid2) * p[2])
  if m1 > m2:
    down = mid1
  else:
    up = mid2
var ans = 0.0
for p in chokudai:
  ans = max(ans, max(abs(p[0] - left) * p[2], abs(p[1] - down) * p[2]))
echo(ans)
