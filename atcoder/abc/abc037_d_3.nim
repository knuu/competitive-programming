import strutils, sequtils, algorithm
let
  t = stdin.readline.split.map(parseInt)
  (H, W) = (t[0], t[1])
var
  A: seq[seq[int]] = @[]
  num: seq[(int, int, int)] = @[]

for i in 0..<H:
  A.add(stdin.readline.split.map(parseInt))
  for j, n in A[^1]:
    num.add((n, i, j))
num.sort(cmp)
var
  dp = newSeqWith(H, newSeqWith(W, 1.int64))
  ans = 0.int64

let
  dhw = @[(-1, 0), (0, 1), (1, 0), (0, -1)]
  m = (1e9.int + 7).int64
for c in num:
  let (n, h, w) = c
  ans = (ans + dp[h][w]) mod m
  for d in dhw:
    let
      (dh, dw) = d
      nh = h + dh
      nw = w + dw
    if 0 <= nh and nh < H and 0 <= nw and nw < W and A[nh][nw] > A[h][w]:
      dp[nh][nw] = (dp[nh][nw] + dp[h][w]) mod m
ans.echo
