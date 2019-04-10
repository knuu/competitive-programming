import strutils, sequtils, math
let
  N = stdin.readline.parseBiggestInt
  input = stdin.readline.split.map(parseBiggestInt)
  (a, b, c) = (input[0], input[1], input[2])
  ab = lcm(a, b)
  bc = lcm(b, c)
  ca = lcm(c, a)
  abc = lcm(ab, c)
echo(N div a + N div b + N div c - N div ab - N div bc - N div ca + N div abc)
