import strutils
let N = stdin.readline.parseFloat
echo((N * 1.08 + 1e-9).formatFloat(ffDecimal, 2))
