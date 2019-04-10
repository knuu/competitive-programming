import sequtils, strutils
let tv = stdin.readline.split.map(parseInt)
echo(if tv[0] > tv[1]: "TATE" else: "YOKO")
