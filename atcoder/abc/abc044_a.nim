import strutils

let
  N = stdin.readline.parseInt
  K = stdin.readline.parseInt
echo(min(K, N) * stdin.readline.parseInt + max(0, N - K) * stdin.readline.parseInt)
