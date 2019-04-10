import strutils, sequtils, algorithm, math
let
  tmp = stdin.readline.split.map(parseInt)
  (H, W, K) = (tmp[0], tmp[1], tmp[2])
var inv_num = newSeq[(int, int, int)]()
for r in 0..<H:
  for c in 0..<W:
    inv_num.add(((H-1) - r + (W-1) - c, r, c))
inv_num.sort(cmp)
var
  res = K
  ans = newSeqWith(H, newSeqWith(W, -1))
  cnt = 0
  rest = newSeq[(int, int)]()

for p in reversed(inv_num):
  let (v, r, c) = p
  if v <= res:
    ans[r][c] = H * W - cnt
    cnt.inc
    res -= v
  else:
    rest.add((r, c))
for i, p in rest:
  let (r, c) = p
  ans[r][c] = i+1
ans.mapIt(it.mapIt(it.intToStr).join(" ")).join("\n").echo
