import strutils, tables, algorithm
let N = stdin.readline.parseInt
var
  A, A_set: seq[int] = @[]
  map = initTable[int, int]()

for _ in 0..<N:
  A.add(stdin.readline.parseInt)
  if map.hasKeyOrPut(A[^1], 0) == false:
    A_set.add(A[^1])

A_set.sort(cmp)
for i, a in A_set:
  map[a] = i
for a in A:
  map[a].echo
