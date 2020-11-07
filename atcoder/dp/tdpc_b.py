import sys
sys.setrecursionlimit(10**6)
if sys.version[0] == '2':
    range, input = xrange, raw_input


def dfs(da, db, turn):
    stack = list()
    stack.append((turn, da, db, True))
    while stack:
        a, b, t, flag = stack[-1]
        if flag:
            stack[-1] = (a, b, t, False)
            if dp[t][a][b] != -1:
                stack.pop()
                continue
            if a < A:
                stack.append((a + 1, b, t ^ 1, True))
            if b < B:
                stack.append((a, b + 1, t ^ 1, True))
        else:
            stack.pop()
            dp[t][a][b] = (0, 0)
            if a < A:
                cand = dp[t^1][a+1][b]
                dp[t][a][b] = max(dp[t][a][b], (cand[1] + mA[a], cand[0]))
            if b < B:
                cand = dp[t^1][a][b+1]
                dp[t][a][b] = max(dp[t][a][b], (cand[1] + mB[b], cand[0]))
    return dp[0][0][0]

A, B = map(int, input().split())
dp = [[[-1] * (B + 1) for _ in range(A + 1)] for _ in range(2)]
mA = [int(x) for x in input().split()]
mB = [int(x) for x in input().split()]

print(dfs(0, 0, 0)[0])
