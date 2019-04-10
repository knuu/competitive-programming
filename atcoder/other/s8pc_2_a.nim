let S = stdin.readline
var
  ans = 0
  now = 'I'
for s in S:
  if s == now:
    ans.inc
    now = if now == 'I': 'O' else: 'I'
if now == 'I':
  ans.dec
echo(max(0, ans))
