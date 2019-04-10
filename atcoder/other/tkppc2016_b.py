N, M = map(int, input().split())

dp = [[0] * (M+1) for _ in range(N+1)]

for i in range(N):
    v, t = map(int, input().split())
    for j in range(M+1):
        if j - t >= 0:
            dp[i+1][j] = max(dp[i][j], dp[i][j-t] + v)
        else:
            dp[i+1][j] = dp[i][j]
print(max(dp[N]))
