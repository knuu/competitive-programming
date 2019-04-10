import strutils

let S = stdin.readline

if S[^2..(^1)] == "ai":
  echo(S[0..<(^2)], "AI")
else:
  echo(S, "-AI")