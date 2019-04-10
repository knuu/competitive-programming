import strutils, sequtils

let
  input = stdin.readline.split.map(parseBiggestInt)
  (a, b, x) = (input[0], input[1], input[2])
echo(b div x - a div x + (if a mod x == 0: 1.int64 else: 0.int64))
