import strutils, sequtils
let
  input = stdin.readline.split.map(parseInt)
  (N, H, M, T) = (input[0], input[1], input[2], input[3])
  wake = (H * 60 + M + (N - 1) * T mod 1440) mod 1440
echo(wake div 60)
echo(wake mod 60)
