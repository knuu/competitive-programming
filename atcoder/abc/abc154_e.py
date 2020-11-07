N = input()
L = len(N)
K = int(input())
dp = [[[0] * 2 for _ in range(K + 1)] for _ in range(L + 1)]
dp[0][0][1] = 1
for i, x in zip(range(L), map(int, N)):
    for k in range(K):
        dp[i+1][k][0] += dp[i][k][0]  # d == 0
        if x == 0:
            dp[i+1][k][1] += dp[i][k][1]
        elif x > 0:
            dp[i+1][k][0] += dp[i][k][1]
        # d != 0
        for d in range(1, 10):
            dp[i+1][k+1][0] += dp[i][k][0]
            if d == x:
                dp[i+1][k+1][1] += dp[i][k][1]
            elif d < x:
                dp[i+1][k+1][0] += dp[i][k][1]
    dp[i+1][K][0] += dp[i][K][0]  # k == K and d == 0
    if x == 0:
        dp[i+1][K][1] += dp[i][K][1]
    elif x > 0:
        dp[i+1][K][0] += dp[i][K][1]
print(sum(dp[-1][K]))
