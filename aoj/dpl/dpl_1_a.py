n, m = map(int, input().split())
C = list(map(int, input().split()))
INF = 10**5
dp = [INF for _ in range(n+1)]
dp[0] = 0
for i in range(n):
    for c in C:
        if i + c <= n:
            dp[i+c] = min(dp[i+c], dp[i]+1)
print(dp[n])
