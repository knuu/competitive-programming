N = input()

dp = [[[0] * 2 for _ in range(10)] for _ in range(len(N)+1)]
dp[0][0][0] = 1
for i in range(len(N)):
    for j in range(10):
        for k in range(10):
            dp[i+1][k][1] += dp[i][j][1]
        if j < int(N[i]):
            for k in range(10):
                dp[i+1][k][1] += dp[i][j][0]
        elif j == int(N[i]):
            for k in range(N):
                pass
        else:
            for k in range(j, 10):
                dp[i+1][k][0] += dp[i][j][0]
print(sum(dp[i+1][1][1] * (10 ** (len(N)-i-1)) for i in range(len(N))))
