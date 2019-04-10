import strutils, sequtils, algorithm
echo(if stdin.readline.split.map(parseInt).sorted(cmp) == @[5, 5, 7]: "YES" else: "NO")
