let S = stdin.readline

var
  cnt = 0
  now = S[0]
for s in S:
  if s != now:
    cnt.inc
    now = s
cnt.echo
