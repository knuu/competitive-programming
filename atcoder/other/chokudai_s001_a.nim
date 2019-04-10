import sequtils, strutils

discard stdin.readline
stdin.readline.split.map(parseInt).max.echo
