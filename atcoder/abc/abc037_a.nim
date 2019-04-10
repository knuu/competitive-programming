import strutils, sequtils, algorithm
let input = stdin.readline.split.map(parseInt)
var (A, B, C) = (input[0], input[1], input[2])
echo(C div min(A, B))
