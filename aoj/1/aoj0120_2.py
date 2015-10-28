import sys
from math import sqrt

testcases = [[int(x) for x in line.split()] for line in sys.stdin.readlines()]

for testcase in testcases:
    box, *cakes = testcase
    N = len(cakes)
    INF = box + 1
    dp = [[INF] * N for _ in range(1 << N)]
    dp[(1 << N) - 1][0] = 0
    for state in reversed(range(1 << N)):
        for v in range(N):
            if not dp[state][v]:
                continue
            for u in range(N):
                if not (state >> u & 1):
                    dp[state][v] = min(dp[state][v], dp[state | 1 << u][u] + sqrt(pow(cakes[u] + cakes[v], 2) - pow(cakes[u] - cakes[v], 2)))
    print('OK' if min(dp[0]) <= box else 'NA')
