import strutils, sequtils

let B = stdin.readline.split.map(parseInt)

for i in 1..10:
  if B.allIt(it != i):
    i.echo
