import strutils, sequtils, algorithm, math

let
  tmp = stdin.readline.split.map(parseInt)
  (N, M) = (tmp[0], tmp[1])
var edge = newSeqWith(N, newSeq[int]())

for i in 0..<M:
  let
    e = stdin.readline.split.mapIt(it.parseInt-1)
    (a, b) = (e[0], e[1])
  edge[a].add(b)
  edge[b].add(a)

var used = newSeq[bool](N)
let (s, t) = (0, edge[0][0])
used[s] = true
used[t] = true

var ans = newSeqWith(2, newSeq[int]())
ans[0].add(s + 1)
ans[1].add(t + 1)

for i, start in @[s, t]:
  var v = start
  while edge[v].anyIt(not used[it]):
    for c in edge[v]:
      if not used[c]:
        v = c
        used[c] = true
        ans[i].add(c + 1)
        break

echo(ans.mapIt(it.len).sum)
(ans[0].reversed & ans[1]).mapIt(it.intToStr).join(" ").echo
