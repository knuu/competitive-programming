import strutils, sequtils

let
  A = stdin.readline
  B = stdin.readline

echo(if A.allIt(it.isDigit) and B.allIt(it.isDigit) and (A.len == 1 or A[0] != '0') and (B.len == 1 or B[0] != '0') and max(A.parseInt, B.parseInt) <= 12345: "OK" else: "NG")
