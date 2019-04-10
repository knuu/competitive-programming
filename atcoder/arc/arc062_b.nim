import strutils
let
  S = stdin.readline
echo((S.count('g') - S.count('p')) div 2)
