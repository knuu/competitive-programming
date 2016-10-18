import strutils, math
let N = stdin.readline.parseInt
for i in 1..pow(1e9, 1/4).int:
  if i*i*i*i == N:
    echo(i)
    break
