import strutils

let S = stdin.readline

var flag = false
for i in 0..<(S.len-2):
  if S[i] == S[i + 1] and S[i + 1] == S[i + 2]:
    echo(if S[i] == 'O': "East" else: "West")
    flag = true
    break
if not flag:
  echo("NA")
