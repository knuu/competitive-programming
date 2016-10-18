import strutils, sequtils
let
  m = (1e9.int + 7).int64
  t = stdin.readline.split.map(parseBiggestInt)
echo(t[0] * t[1] mod m * t[2] mod m)
