import strutils, sequtils
let
  input = stdin.readline.split
  (A, B) = (input[0], input[1])
if A.len != B.len:
   echo(if A.len > B.len: A else: B)
else:
  for i in 0..<A.len:
    var
      a = A[i]
      b = B[i]
    if a != b:
      if a == '4' and b == '7':
        echo(A)
      elif a == '7' and b == '4':
        echo(B)
      else:
        echo(if a > b: A else: B)
      break
