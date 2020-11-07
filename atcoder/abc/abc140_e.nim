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

type CMultiSet {.importcpp: "std::multiset", header: "<set>".} [T] = object
type CMultiSetIter {.importcpp: "std::multiset<'0>::iterator", header: "<set>".} [T] = object
proc cInitMultiSet(T: typedesc): CMultiSet[T] {.importcpp: "std::multiset<'*1>()", nodecl.}
proc initMultiSet*[T](): CMultiSet[T] = cInitMultiSet(T)
proc insert*[T](self: var CMultiSet[T],x:T) {.importcpp: "#.insert(@)", nodecl.}
proc empty*[T](self: CMultiSet[T]):bool {.importcpp: "#.empty()", nodecl.}
proc size*[T](self: CMultiSet[T]):int {.importcpp: "#.size()", nodecl.}
proc clear*[T](self:var CMultiSet[T]) {.importcpp: "#.clear()", nodecl.}
proc erase*[T](self: var CMultiSet[T],x:T) {.importcpp: "#.erase(@)", nodecl.}
proc find*[T](self: CMultiSet[T],x:T): CMultiSetIter[T] {.importcpp: "#.find(#)", nodecl.}
proc lower_bound*[T](self: CMultiSet[T],x:T): CMultiSetIter[T] {.importcpp: "#.lower_bound(#)", nodecl.}
proc upper_bound*[T](self: CMultiSet[T],x:T): CMultiSetIter[T] {.importcpp: "#.upper_bound(#)", nodecl.}
proc begin*[T](self:CMultiSet[T]):CMultiSetIter[T]{.importcpp: "#.begin()", nodecl.}
proc `end`*[T](self:CMultiSet[T]):CMultiSetIter[T]{.importcpp: "#.end()", nodecl.}
proc `*`*[T](self: CMultiSetIter[T]):T{.importcpp: "*#", nodecl.}
proc `++`*[T](self:var CMultiSetIter[T]){.importcpp: "++#", nodecl.}
proc `--`*[T](self:var CMultiSetIter[T]){.importcpp: "--#", nodecl.}
proc `==`*[T](x,y:CMultiSetIter[T]):bool{.importcpp: "#==#", nodecl.}
proc `==`*[T](x,y:CMultiSet[T]):bool{.importcpp: "#==#", nodecl.}
import sequtils # nim alias
proc add*[T](self:var CMultiSet[T],x:T) = self.insert(x)
proc len*[T](self:CMultiSet[T]):int = self.size()
proc min*[T](self:CMultiSet[T]):T = *self.begin()
proc max*[T](self:CMultiSet[T]):T = (var e = self.`end`();--e; *e)
proc contains*[T](self:CMultiSet[T],x:T):bool = self.find(x) != self.`end`()
iterator items*[T](self:CMultiSet[T]) : T =
  var (a,b) = (self.begin(),self.`end`())
  while a != b : yield *a; ++a
proc `>`*[T](self:CMultiSet[T],x:T) : seq[T] =
  var (a,b) = (self.upper_bound(x),self.`end`())
  result = @[]; while a != b :result .add *a; ++a
proc `>=`*[T](self:CMultiSet[T],x:T) : seq[T] =
  var (a,b) = (self.lower_bound(x),self.`end`())
  result = @[]; while a != b :result .add *a; ++a
proc toMultiSet*[T](arr:seq[T]): CMultiSet[T] = (result = initMultiSet[T]();for a in arr: result.add(a))
proc toSeq[T](self:CMultiSet[T]):seq[T] = self.mapIt(it)
proc `$`*[T](self:CMultiSet[T]): string = $self.mapIt(it)

when isMainModule:
  let
    N = input(int, 1)
    P = input(int)
  var order = newSeq[int](N)
  for i, p in P:
    order[p-1] = i

  var mset = toMultiSet[int](@[-1, -1, N, N])

  var ans = 0
  for i in countdown(N-1, 0):
    let
      p_i = i+1
      idx = order[i]
    var it = mset.lower_bound(idx)
    let next = *it
    ++it
    let nnext = *it
    --it
    --it
    let prev = *it
    --it
    let pprev = *it
    ans += ((nnext - next) * (idx - prev) + (next - idx) * (prev - pprev)) * p_i
    mset.insert(idx)
  ans.echo
