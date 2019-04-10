import strutils, sequtils

let
  t = stdin.readline.split.map(parseInt)
  (H, W) = (t[0], t[1])
echo((H-1)*W+H*(W-1))
