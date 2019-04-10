import strutils, sequtils
let
  input = stdin.readline.split.map(parseInt)
  A = input[0]
  B = input[1]
  M = 2 * (1e9.int)
  cnt = [min(A, B) - 1, max(A, B) - min(A, B) - 1, M - max(A, B)]
if A < B:
  echo(cnt[0] + cnt[1])
else:
  echo(cnt[1] + cnt[2])
