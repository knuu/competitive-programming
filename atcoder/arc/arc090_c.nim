import algorithm, complex, future, macros, math, queues, rationals, sets, sequtils, strutils, tables # for 0.13.0
# import algorithm, bitops, complex, deques, heapqueue, lenientops, macros, math, queues, rationals, sets, sequtils, strformat, strscans, strutils, sugar, tables # for 0.19

# ----- input macro by nimon -----

macro unpack*(input: seq; count: static[int]): untyped =
  result = quote do: ()
  when NimMinor <= 13:
    for i in 0..<count: result[0].add quote do: `input`[`i`]
  else:
    for i in 0..<count: result.add quote do: `input`[`i`]

## count == 0 のとき unpackしない(seq)
## count >  0 のとき count個分 unpack した結果の tuple を返す
type UnselectableTypeError = object of Exception
template input*(typ: typedesc; count: Natural = 0): untyped =
  let line = stdin.readLine.split
  when count == 0:
    when typ is int:    line.map(parseInt)
    elif typ is float:  line.map(parseFloat)
    elif typ is string: line
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")
  else:
    when typ is int:    line.map(parseInt).unpack(count)
    elif typ is float:  line.map(parseFloat).unpack(count)
    elif typ is string: line.unpack(count)
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")

# 2-dim table
template inputs*(typ: typedesc; count = 0; rows = 1): untyped =
  (1..rows).mapIt(input(typ, count))

# ----- end input macro -----

# from https://nim-lang.org/docs/manual.html#macros-expression-macros
# when NimMinor >= 16, you can use future.dump (sugar.dump)
macro debug(args: varargs[untyped]): untyped =
  result = nnkStmtList.newTree()
  for n in args:
    result.add newCall("write", newIdentNode("stderr"), newLit(n.repr))
    result.add newCall("write", newIdentNode("stderr"), newLit(": "))
    result.add newCall("write", newIdentNode("stderr"), n)
    result.add newCall("writeLine", newIdentNode("stderr"), newLit(""))

const MOD = 10^9 + 7
const INF = high(int)

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
    (N, M) = input(int, 2)
    (S, T) = input(int, 2)
    (start, goal) = (S-1, T-1)
  var
    edges = newSeqWith(N, newseq[(int, int)]())
  for i in 0..<N:
    let (u, v, d) = input(int, 3)
    edges[u-1].add((v-1, d))
    edges[v-1].add((u-1, d))

  var
    pque = initHeap[(int, int)](proc (x: (int, int), y: (int, int)): int = cmp(y, x))
    dist = newSeqWith(N, INF)
  pque.push((0, start))
  while not pque.empty:
    let
      (cost, v) = pque.pop
    if dist[v] < cost:
      continue
    dist[v] = cost
    for e in edges[v]:
      let (u, d) = e
      if dist[v] + d < dist[u]:
        pque.push((dist[v] + d, u))
  let sp_dist = dist[goal]

  var
    dag = newSeqWith(N, newseq[(int, int)]())

  var
    stack = newseq[int]()
    used = newseq[bool](N)

  stack.add(goal)
  while stack.len > 0:
    let v = stack.pop
    if used[v]:
      continue
    used[v] = true
    for e in edges[v]:
      let (u, d) = e
      if dist[u] + d == dist[v]:
        dag[u].add((v, d))
        stack.add(u)
  dag.echo
  var
    order = newSeqWith(N, -1)
    cnt = 0
