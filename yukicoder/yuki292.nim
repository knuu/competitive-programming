import strutils
let
  input = stdin.readline.split
  (S, t, u) = (input[0], input[1].parseInt, input[2].parseInt)
for i, s in S:
  if i != t and i != u:
    stdout.write(s)
echo()
