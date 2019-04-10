import strutils, sequtils, math

let flags = stdin.readline.split.map(parseInt)
if flags[^1] == 1 or flags[0..<(^1)].sum < 2:
  echo("SURVIVED")
else:
  echo("DEAD")
