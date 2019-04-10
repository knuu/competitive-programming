import strutils, sequtils, algorithm

let candy = stdin.readline.split.map(parseInt).sorted(cmp)

echo(if candy[0] + candy[1] == candy[2]: "Yes" else: "No")
