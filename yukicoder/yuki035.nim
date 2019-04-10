import strutils, sequtils

let N = stdin.readline.parseInt
var all_type, can_type = 0
for _ in 0..<N:
  let
    t = stdin.readline.split
    (T, S) = (t[0].parseInt, t[1].len)
  all_type += S
  can_type += min(S, 12 * T div 1000)
echo(can_type, ' ', all_type - can_type)
