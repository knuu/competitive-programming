import strutils, sequtils

let
  input = stdin.readline.split.map(parseBiggestInt)
  (N, A, B, C, D) = (input[0].int, input[1], input[2], input[3], input[4])

for i in 0..<N:
  if C * (N - 1 - i).int64 - D * i.int64 <= B - A and B - A <= -C * i.int64 + D * (N - 1 - i).int64:
    echo("YES")
    quit()
echo("NO")
