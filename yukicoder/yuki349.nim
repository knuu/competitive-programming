import strutils, tables

var
  N = stdin.readline.parseInt
  counter = toCountTable(@["ne", "ushi", "tora", "u", "tatsu", "mi", "uma", "hitsuji", "saru", "tori", "inu", "i"])
for _ in 0..<N:
  counter.inc(stdin.readline)
if (N mod 2 == 0 and counter.largest.val * 2 <= N) or (N mod 2 == 1 and counter.largest.val * 2 - 1 <= N):
  echo("YES")
else:
  echo("NO")
