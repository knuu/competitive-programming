import strutils, sequtils, math
let scores = stdin.readline.split.map(parseInt)
echo(((scores.sum - scores.min - scores.max) / (scores.len - 2)).formatFloat(ffDecimal, 2))
