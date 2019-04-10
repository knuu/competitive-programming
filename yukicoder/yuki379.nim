import strutils, sequtils
let t = stdin.readline.split.map(parseFloat)
echo(((t[0].int div 5).float * t[1] / t[2]).formatFloat(ffDecimal, 32))
