import strutils

let S = stdin.readline.split
echo(if S[1] == "+": S[0].parseInt + S[2].parseInt else: S[0].parseInt - S[2].parseInt)
