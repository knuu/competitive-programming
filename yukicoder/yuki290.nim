import strutils
let
  N = stdin.readline.parseInt
  S = stdin.readline
echo(if N == 1 or S == "01" or S == "10" or S == "010" or S == "101": "NO" else: "YES")
