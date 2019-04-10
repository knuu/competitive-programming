import sequtils, strutils, algorithm

discard stdin.readline
stdin.readline.split.map(parseInt).sorted(cmp).mapIt(it.intToStr).join(" ").echo
