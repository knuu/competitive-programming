# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

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


when isMainModule:
  let
    N = getInteger
    A = getBigIntSeq
  var
    left = newSeq[int64](N + 1)
    right = newSeq[int64](N + 1)
    pque = initHeap[int64]()
    num_sum = 0.int64
  for i in 0..<N:
    pque.push(A[i])
    num_sum += A[i]
  for i in 0..N:
    left[i] = num_sum
    pque.push(A[i + N])
    num_sum += A[i + N] - pque.pop
  pque = initHeap[int64]()
  num_sum = 0
  for i in 1..N:
    pque.push(-A[^i])
    num_sum += A[^i]
  for i in 0..N:
    right[N - i] = num_sum
    pque.push(-A[^(N + i + 1)])
    num_sum += A[^(N + i + 1)] + pque.pop
  left.zip(right).mapIt(it[0] - it[1]).max.echo
