from strutils import parseInt
var
  left = 1
  right = 1e9.toint + 1
while left + 1 < right:
  let mid = (left + right) div 2
  echo("? ", mid)
  flushFile(stdout)
  if stdin.readline.parseInt == 0:
    right = mid
  else:
    left = mid
echo("! ", left)
flushFile(stdout)
