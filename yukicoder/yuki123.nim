import sequtils, strutils
let
  t = stdin.readline.split.map(parseInt)
  (N, M) = (t[0], t[1])
  A = stdin.readline.split.mapIt(it.parseInt-1)
var cards = newSeq[int](N)
for i in 0..<N:
  cards[i] = i+1
for a in A:
  var tmp = newSeq[int]()
  tmp.add(cards[a])
  for i, c in cards:
    if i != a:
      tmp.add(c)
  cards = tmp
cards[0].echo
