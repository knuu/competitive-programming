import strutils, sequtils
let
  N = stdin.readline.parseInt
  K = stdin.readline.split.map(parseInt)
var
  dp = newSeqWith(1 shl N, -1)

proc is_kadomatsu(A, B, C: int): bool =
  return A != B and B != C and C != A and (max(A, C) < B or min(A, C) > B)

proc dpdp(state: int): int =
  if dp[state] != -1:
    return dp[state]
  for i in 0..<N:
    for j in i+1..<N:
      for k in j+1..<N:
        if is_kadomatsu(K[i], K[j], K[k]) and ((state shr i) and 1) == 0 and ((state shr j) and 1) == 0 and ((state shr k) and 1) == 0 and dpdp(state or (1 shl i) or (1 shl j) or (1 shl k)) == 0:
          dp[state] = 1
          return 1
  dp[state] = 0
  return 0

proc main() =
  if dpdp(0) == 0:
    echo(-1)
    return
  else:
    for a in 0..<N:
      for b in a+1..<N:
        for c in b+1..<N:
          if dp[(1 shl a) or (1 shl b) or (1 shl c)] == 0:
            echo(a, ' ', b, ' ', c)
            return
main()
