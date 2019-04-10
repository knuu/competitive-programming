import sequtils
let S = stdin.readline
var cnt = newSeqWith(26, 0)

for s in S:
  cnt[s.ord - 'a'.ord].inc

var odd, even = 0

for c in cnt:
  even += c div 2
  odd += c mod 2

if odd == 0:
  echo(even * 2)
else:
  echo(1 + even div odd * 2)
