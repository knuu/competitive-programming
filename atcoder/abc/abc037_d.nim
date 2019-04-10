import strutils, sequtils, algorithm, math
let
  t = stdin.readline.split.map(parseInt)
  (H, W) = (t[0], t[1])
var
  A: array[1000, array[1000, int]]
  num: seq[(int, int, int)] = @[]

for i in 0..<H:
  for j, n in stdin.readline.split.map(parseInt):
    A[i][j] = n
    num.add((n, i, j))
num.sort(cmp)
var dp: array[1000, array[1000, int64]]

let
  dhw = @[(-1, 0), (0, 1), (1, 0), (0, -1)]
  m = (1e9.int + 7).int64
var ans = 0.int64
for c in num:
  let (n, h, w) = c
  dp[h][w] = (dp[h][w] + 1) mod m
  ans += dp[h][w]
  for d in dhw:
    let
      (dh, dw) = d
      nh = h + dh
      nw = w + dw
    if 0 <= nh and nh < H and 0 <= nw and nw < W and A[nh][nw] > n:
      dp[nh][nw] += dp[h][w]
echo(ans mod m)
