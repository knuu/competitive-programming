N, T = map(int, input().split())
A = [int(input()) for _ in range(N)]
dp = [0] * (10**6 + T + 2)
for a in A:
    dp[a] += 1
    dp[a+T] -= 1
ans = 1 if dp[0] > 0 else 0
for i in range(10**6 + T + 1):
    dp[i+1] += dp[i]
    if dp[i+1] > 0: ans += 1
print(ans)
