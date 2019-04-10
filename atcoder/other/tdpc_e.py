D = int(input())
N = [int(x) for x in input()]

dp = [[[0] * D for j in range(2)] for i in range(len(N) + 1)]
dp[0][1][0] = 1
mod = int(1e9) + 7
for i in range(len(N)):
    for k in range(D):
        for d in range(10):
            dp[i + 1][0][k] += dp[i][0][(k + D - d) % D]
        for d in range(N[i]):
            dp[i + 1][0][k] += dp[i][1][(k + D - d) % D]
        dp[i + 1][1][k] = dp[i][1][(k + D - N[i]) % D]
        dp[i + 1][0][k] %= mod
        dp[i + 1][1][k] %= mod
print((dp[len(N)][0][0] + dp[len(N)][1][0] + mod - 1) % mod)
