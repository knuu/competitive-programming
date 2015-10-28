import sys
from math import sqrt


def rec(state, v):
    if state == (1 << N) - 1:
        return cakes[v]
    if dp[state][v] != -1:
        return dp[state][v]

    ret = INF
    for i in range(N):
        if state == 0:
            ret = min(ret, rec(1 << i, i) + cakes[i])
        elif not (state >> i & 1):
            ret = min(ret, rec(state | 1 << i, i) + sqrt(pow(cakes[i] + cakes[v], 2) - pow(cakes[i] - cakes[v], 2)))
    dp[state][v] = ret
    return ret


testcases = [[int(x) for x in line.split()] for line in sys.stdin.readlines()]

for testcase in testcases:
    box, *cakes = testcase
    N = len(cakes)
    INF = box + 1
    dp = [[-1] * N for _ in range(1 << N)]
    print('OK' if rec(0, 0) <= box else 'NA')
