X = int(input())
dp = [-1] * (X + 1)
dp[0] = 0
for val in [100, 101, 102, 103, 104, 105]:
    for j in range(X+1):
        if dp[j] >= 0:
            dp[j] = 1000000
        elif j < val or dp[j - val] <= 0:
            dp[j] = -1
        else:
            dp[j] = dp[j - val] - 1
print(1 if dp[-1] >= 0 else 0)
