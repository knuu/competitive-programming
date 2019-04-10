import strutils, sequtils
var
  input = stdin.readline.split.map(parseInt)
if input[1] == input[0] * input[1]:
  echo('=')
else:
  echo("!=")
