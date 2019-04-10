import strutils, sequtils
var
  S = stdin.readline
  pos = stdin.readline.split.map(parseInt)
echo(S.substr(0, pos[0]-1), '"', S.substr(pos[0], pos[1]-1), '"', S.substr(pos[1], pos[2]-1), '"', S.substr(pos[2], pos[3]-1), '"', S.substr(pos[3], S.len-1))
