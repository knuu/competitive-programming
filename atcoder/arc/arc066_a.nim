import strutils, sequtils, tables, math

proc powmod[T](x, k, m: T): T =
  if k == 0:
    result = 1
  elif k mod 2 == 0:
    let x = powmod(x, k shr 1, m)
    result = x * x mod m
  else:
    result = powmod(x, k-1, m) * x mod m

let N = stdin.readline.parseInt
var cnt = initTable[int, int]()
for a in stdin.readline.split.map(parseInt):
  cnt[a] = cnt.getOrDefault(a) + 1
if N mod 2 == 1 and (not cnt.contains(0) or cnt[0] != 1):
  echo(0)
  quit()
let start = if N mod 2 == 0: 1 else: 2
for i in countup(start, N, 2):
  if not cnt.contains(i) or cnt[i] != 2:
    echo(0)
    quit()
powmod(2, N div 2, 1e9.int + 7).echo
