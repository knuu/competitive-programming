def dfs(v, c):
    if v == 0:
        return 1
    elif v < 0 or c >= M:
        return 0
    elif memo[c][v] != -1:
        return memo[c][v]
    memo[c][v] = dfs(v, c + 1) + dfs(v - C[c], c)
    return memo[c][v]

N, M = map(int, input().split())
C = [int(x) for x in input().split()]
memo = [[-1] * (N + 1) for _ in range(len(C))]
print(dfs(N, 0))
