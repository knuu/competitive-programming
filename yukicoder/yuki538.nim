import strutils, sequtils

let
  input = stdin.readline.split.map(parseBiggestInt)
  (b1, b2, b3) = (input[0], input[1], input[2])
echo((b3 * b3 + b2 * b2 - b2 * b3 - b1 * b3) div (b2 - b1))
