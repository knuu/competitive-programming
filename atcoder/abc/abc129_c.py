N, M = map(int, input().split())
dp = [0] * (N + 1)
dp[0] = 1
kaidan = [True] * (N + 1)
MOD = 10 ** 9 + 7
for _ in range(M):
    kaidan[int(input())] = False
for i in range(N):
    if kaidan[i]:
        dp[i+1] += dp[i]
    if i > 0 and kaidan[i-1]:
        dp[i+1] += dp[i-1]
    dp[i+1] %= MOD
print(dp[-1])
