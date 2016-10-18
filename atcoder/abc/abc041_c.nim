import strutils, algorithm, sequtils
let
  N = stdin.readline.parseInt
  A = stdin.readline.split.map(parseInt)
var students = newSeq[(int, int)](N)
for i, a in A: students[i] = (a, i+1)
students.sort(cmp)

for student in students.reversed:
  student[1].echo
