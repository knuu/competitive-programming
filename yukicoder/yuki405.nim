import strutils, sequtils

let
  tmp = stdin.readline.split
  (S1, T) = (tmp[0], tmp[1].parseInt)
  roman = @["I","II","III","IIII","V","VI","VII","VIII","IX","X","XI","XII"]
roman[(roman.find(S1)+T+12*(1000 div 12 + 1)) mod 12].echo
