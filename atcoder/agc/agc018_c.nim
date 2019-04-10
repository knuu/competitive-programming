import sequtils, strutils, algorithm

type
  Heap[T]= object
    data: seq[T]
    size: int
    comp: proc (x: T, y: T): int
  EmptyHeapError = object of Exception

proc siftup[T](h: var Heap[T]) =
  var i = h.size - 1
  while i > 0:
    var par = (i-1) div 2
    if h.comp(h.data[par], h.data[i]) > 0:
      swap(h.data[i], h.data[par])
      i = par
    else:
      break
proc siftdown[T](h: var Heap[T]) =
  var par = 0
  while par < h.size:
    let (left, right) = (2*par+1, 2*par+2)
    if right < h.size:
      if h.comp(h.data[par], min(h.data[left], h.data[right])) <= 0:
        break
      elif h.comp(h.data[left], h.data[right]) < 0:
        swap(h.data[par], h.data[left])
        par = left
      else:
        swap(h.data[par], h.data[right])
        par = right
    elif left < h.size:
      if h.comp(h.data[left], h.data[par]) < 0:
        swap(h.data[par], h.data[left])
        par = left
      else:
        break
    else:
      break
proc initHeap[T](comparator: proc (x: T, y: T): int = cmp): Heap[T] =
  Heap[T](data: newSeq[T](), size: 0, comp: comparator)
proc push[T](h: var Heap[T], x: T) =
  h.data.add(x)
  h.size.inc
  h.siftup
proc pop[T](h: var Heap[T]): T =
  if h.size <= 0:
    raise newException(EmptyHeapError, "cannot pop element, heap is empty")
  result = h.data[0]
  h.data[0] = h.data[^1]
  h.size.dec
  h.data.setlen(h.size)
  h.siftdown
proc empty[T](h: var Heap[T]): bool {. inline .} = h.data.len == 0
proc clear[T](h: var Heap[T]) =
  h.data.setLen(0)
  h.size = 0

proc solve(X, Y, Z: int, people: seq[(int64, int64, int64)]) =
  let N = X + Y + Z
  var diff = newSeq[(int64, int)](N)
  for i in 0..<N:
    diff[i] = (people[i][0] - people[i][1], i)
  diff.sort(cmp)

  var
    gold, silver = newSeq[int64](N)
    pque = initHeap[(int64, int)]()
    g_count, s_count, b_count = 0.int64

  for i in 0..<Y:
    let
      (d, idx) = diff[i]
      (x, y, z) = people[idx]
    pque.push((y - z, idx))
    s_count += y
  silver[Y-1] = s_count

  for i in Y..<(N-X):
    let
      (d1, idx1) = pque.pop
      (d2, idx2) = diff[i]
      (x1, y1, z1) = people[idx1]
      (x2, y2, z2) = people[idx2]
    if d1 >= y2 - z2:
      pque.push((d1, idx1))
      b_count += z2
    else:
      pque.push((y2 - z2, idx2))
      s_count += y2 - y1
      b_count += z1
    silver[i] = s_count + b_count

  pque.clear
  b_count = 0.int64

  for i in countdown(N - 1, N - X):
    let
      (d, idx) = diff[i]
      (x, y, z) = people[idx]
    pque.push((x - z, idx))
    g_count += x
  gold[N - X - 1] = g_count

  for i in countdown(N - X - 1, Y):
    let
      (d1, idx1) = pque.pop
      (d2, idx2) = diff[i]
      (x1, y1, z1) = people[idx1]
      (x2, y2, z2) = people[idx2]
    if d1 >= x2 - z2:
      pque.push((d1, idx1))
      b_count += z2
    else:
      pque.push((x2 - z2, idx2))
      g_count += x2 - x1
      b_count += z1
    gold[i - 1] = g_count + b_count

  (0..<N).mapIt(gold[it] + silver[it]).max.echo

when isMainModule:
  let
    input = stdin.readline.split.map(parseInt)
    (X, Y, Z) = (input[0], input[1], input[2])
    N = X + Y + Z
  var people = newSeq[(int64, int64, int64)](N)
  for i in 0..<N:
    let row = stdin.readline.split.map(parseBiggestInt)
    people[i] = (row[0], row[1], row[2])
  solve(X, Y, Z, people)
