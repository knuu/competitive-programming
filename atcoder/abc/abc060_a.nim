import strutils
let S = stdin.readline.split
echo(if S[0][^1] == S[1][0] and S[1][^1] == S[2][0]: "YES" else: "NO")
