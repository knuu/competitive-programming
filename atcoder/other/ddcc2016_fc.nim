import sequtils, strutils

proc solve(A, B, C: int64, S: string) =
  let L = S.len
  var is_flip = newSeqWith(L, 0.int64)
  for i in 0..<(L-1):
    if S[i] != S[i+1]:
      is_flip[i+1].inc
    is_flip[i+1] += is_flip[i]
  var ans = min(A * L.int64 + C * (S[0] == '1').int64, B * L.int64 + C * (S[^1] == '0').int64) + is_flip[^1] * C
  for i in 0..<(L-1):
    ans = min(ans, (i+1).int64 * A + (L - (i+1)).int64 * B + max((S[0] == '1').int64 + is_flip[i] - is_flip[0], (S[^1] == '0').int64 + is_flip[^1] - is_flip[i+1]) * C)
  ans.echo

when isMainModule:
  let
    input = stdin.readline.split.map(parseBiggestInt)
    (A, B, C) = (input[0], input[1], input[2])
    S = stdin.readline
  solve(A, B, C, S)
