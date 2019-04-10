for i in 0..<1000:
  var s = ""
  for _ in 0..<(3-($i).len):
    s.add('0')
  s.add($i)
  echo(s)
  if stdin.readline == "unlocked":
    break
