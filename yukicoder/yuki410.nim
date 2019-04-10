import strutils, sequtils

let
  P = stdin.readline.split.map(parseInt)
  Q = stdin.readline.split.map(parseInt)
echo((abs(P[0]-Q[0]) + abs(P[1]-Q[1]))/2)
