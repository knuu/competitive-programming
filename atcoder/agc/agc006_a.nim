import strutils, sequtils

let
  N = stdin.readline.parseInt
  S = stdin.readline.mapIt(it)
  T = stdin.readline.mapIt(it)

for i in 0..<N:
  if S[i..<N].zip(T).allIt(it[0] == it[1]):
    echo(N + i)
    quit()
echo(2 * N)
