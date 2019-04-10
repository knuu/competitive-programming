import strutils, algorithm, sequtils
var
  N = stdin.readline.parseBiggestInt
  ans = ""
while N >= 0:
  ans.add("ABCDEFGHIJKLMNOPQRSTUVWXYZ"[N mod 26.int64])
  N = N div 26.int64 - 1
echo(ans.reversed.mapIt($it).join)
