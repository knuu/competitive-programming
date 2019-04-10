import sequtils, strutils

discard stdin.readline
echo(stdin.readline.split.map(parseInt).find(1) + 1)
