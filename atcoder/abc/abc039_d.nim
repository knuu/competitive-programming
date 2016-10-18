import sequtils, strutils
let
  t = stdin.readline.split.map(parseInt)
  (R, C) = (t[0], t[1])

var image: seq[string] = @[]
for _ in 1..R: image.add(stdin.readline)

var paint, before: seq[string] = newSeqWith(R, '.'.repeat(C))

let
  dr = @[-1, -1, -1, 0, 0, 0, 1, 1, 1]
  dc = @[-1, 0, 1, -1, 0, 1, -1, 0, 1]

proc in_image(r, c: int): bool = 0 <= r and r < R and 0 <= c and c < C

for r in 0..<R:
  for c in 0..<C:
    if (0..<9).allIt(not in_image(r+dr[it], c+dc[it]) or image[r+dr[it]][c+dc[it]] == '#'):
      before[r][c] = '#'
      for i in 0..<9:
        let (nr, nc) = (r+dr[i], c+dc[i])
        if not in_image(nr, nc): continue
        paint[nr][nc] = '#'
for r in 0..<R:
  if image[r] != paint[r]:
    "impossible".echo
    quit(0)

echo("possible")
for row in before: row.echo
