{.checks: off, optimization: speed.}
import strutils, sequtils, queues

proc popcount(x: int): cint {.
  importc: "__builtin_popcount", nodecl, nosideeffect.}

let N = stdin.readline.parseInt
var
  dist = newSeqWith(N+1, -1)
  que = initQueue[(int, int)]()
dist[1] = 1
que.add((1, 1))
while que.len > 0:
  let (c, v) = que.pop
  if v == N:
    echo(c)
    quit()
  let pcnt = popcount(v)
  for sgn in @[-1, 1]:
    let nv = v + sgn * pcnt
    if 0 < nv and nv <= N and dist[nv] == -1:
      dist[nv] = c + 1
      que.add((c + 1, nv))
echo(-1)
