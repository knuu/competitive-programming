import strutils, sequtils, math

let
  input = stdin.readline.split.map(parseBiggestInt)
  (N, A) = (input[0], input[1])
echo(if N * A == stdin.readline.split.map(parseBiggestInt).sum: "YES" else: "NO")
