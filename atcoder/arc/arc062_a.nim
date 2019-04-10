import strutils, sequtils

let N = stdin.readline.parseInt
var T, A = 1.int64

for _ in 0..<N:
  let
    input = stdin.readline.split.map(parseBiggestInt)
    (t, a) = (input[0], input[1])
    k = max(1.int64, max(T div t + (T mod t != 0).int64, A div a + (A mod a != 0).int64))
  (T, A) = (k * t, k * a)
echo(T + A)
