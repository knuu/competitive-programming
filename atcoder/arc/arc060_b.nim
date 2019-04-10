import strutils, sequtils, math
let
  N = stdin.readline.parseBiggestInt
  S = stdin.readline.parseBiggestInt

if S == N:
  echo(N + 1.int64)
  quit()
if N == 1:
  echo(-1)
  quit()

proc f(b, n: int64): int64 =
  result = if n < b: n else: f(b, n div b) + n mod b

for i in 2..(sqrt(N.float).int+1):
  if f(i.int64, N) == S:
    echo(i)
    quit()

if N - S < 0:
  echo(-1)
  quit()
for i in countdown(sqrt(N.float).int+1, 1):
  if (N - S) mod i == 0 and f((N - S) div i + 1, N) == S:
    echo((N - S) div i + 1)
    quit()
echo(-1)
