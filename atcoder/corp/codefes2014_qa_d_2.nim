# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc popcount[T: int64|int](a: T): cint {. importc: "__builtin_popcountl", nodecl, nosideeffect.}

var
  L, K: int
  A: int64
  A_str: string
  dp: seq[seq[seq[int64]]]

proc getNextState(state, i: int): int =
  if state == 0 and i == 0:
    return 0
  else:
    return state or (1 shl i)

proc dfs(pos, state, flag: int, now: int64): int64 =
  # echo(pos, ':', state, ' ', state.popcount, ' ', flag, ' ', now)
  if pos == L:
    return now
  elif dp[pos][state][flag] != -1:
    return dp[pos][state][flag]
  result = 1e18.int64
  # echo(pos, ':', state, ' ', state.popcount, ' ', flag, ' ', now)
  var cand = 1e18.int64
  if flag == 0:
    for i in 0..<10:
      let next_state = getNextState(state, i)
      if next_state.popcount > K:
        continue
      if i < A_str[pos].ord - '0'.ord:
        cand = dfs(pos + 1, next_state, 1, 10.int64 * now + i.int64)
      elif i > A_str[pos].ord - '0'.ord:
        cand = dfs(pos + 1, next_state, 2, 10.int64 * now + i.int64)
      else:
        cand = dfs(pos + 1, next_state, 0, 10.int64 * now + i.int64)
      if abs(A - cand) < abs(A - result):
        result = cand
  elif flag == 1:
    for i in countdown(9, 0):
      let next_state = getNextState(state, i)
      if next_state.popcount > K:
        continue
      cand = dfs(pos + 1, next_state, flag, 10.int64 * now + i.int64)
      if abs(A - cand) < abs(A - result):
        result = cand
  else:
    for i in 0..<10:
      let next_state = getNextState(state, i)
      if next_state.popcount > K:
        continue
      cand = dfs(pos + 1, next_state, flag, 10.int64 * now + i.int64)
      if abs(A - cand) < abs(A - result):
        result = cand
  dp[pos][state][flag] = result

when isMainModule:
  let
    num = getLine.split
  L = num[0].len
  (A_str, K) = (num[0], num[1].parseInt)
  A = A_str.parseBiggestInt
  dp = newSeqWith(L + 1, newSeqWith(1024, newSeqWith(3, -1.int64)))
  abs(A - dfs(0, 0, 0, 0)).echo
