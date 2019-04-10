import strutils, sequtils, algorithm

discard stdin.readline
let X = stdin.readline.split.map(parseInt).sorted(cmp)
if X[0] != X[1] and zip(X, X[1..^1]).allIt(X[1]-X[0] == it[1]-it[0]): "YES".echo else: "NO".echo
