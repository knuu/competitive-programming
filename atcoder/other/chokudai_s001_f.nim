import strutils, sequtils

discard stdin.readline
let A = stdin.readline.split.map(parseInt)

var
  now = -1
  cnt = 0

for a in A:
  if now < a:
    now = a
    cnt.inc
cnt.echo
