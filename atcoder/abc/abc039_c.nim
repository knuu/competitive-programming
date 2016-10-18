let
  S = stdin.readline
  M = "WBWBWWBWBWBW"
  ans = @["Do", "", "Re", "", "Mi", "Fa", "", "So", "", "La", "", "Si"]
  L = M.len
for i in 0..<L:
  var flag = true
  for j in 0..<L:
    flag = flag and (S[j] == M[(i+j) mod L])
  if flag:
    ans[i].echo
