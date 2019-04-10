N, D, X = map(int, input().split())
INF = 10 ** 5
dp = [0] * (INF + 1)
P = [tuple(map(int, input().split())) for _ in range(D)]
for i in range(X + 1):
    dp[i] = i
ans = X
for d in range(D - 1):
    for i in range(ans + 1):
        dp[i] = i
    tmp = ans
    for i in range(N):
        for j in range(P[d][i], ans + 1):
            dp[j] = max(dp[j], dp[j - P[d][i]] + P[d + 1][i])
            tmp = max(tmp, dp[j])
            print(dp[:10])
    ans = tmp
print(ans)
