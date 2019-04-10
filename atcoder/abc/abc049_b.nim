import sequtils, strutils
let
  input = stdin.readline.split.map(parseInt)
  (H, W) = (input[0], input[1])
var image = newSeq[string](H)

for i in 0..<H:
  image[i] = stdin.readline

for i in 0..<(2*H):
  for j in 0..<W:
    stdout.write(image[i div 2][j])
  echo()
