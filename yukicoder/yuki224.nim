import sequtils, math, future
discard stdin.readline
let
  S = stdin.readline
  T = stdin.readline
lc[0 | (i <- 0..<S.len, S[i] != T[i]), int].len.echo
