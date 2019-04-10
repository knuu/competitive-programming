import strutils, sequtils
let t = stdin.readline.split.map(parseInt)
if t[1] > t[0]:
  stdout.write('+')
echo(t[1] - t[0])
