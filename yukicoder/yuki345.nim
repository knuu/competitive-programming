var
  S = stdin.readline
  ans = -1
for i in 0..<S.len:
  if S[i] == 'c':
    var
      cnt = 0
      pos = i
    while pos < S.len and cnt < 2:
      if S[pos] == 'w': cnt.inc
      pos.inc
    if cnt == 2 and (ans == -1 or pos - i < ans):
      ans = pos - i
echo(ans)
