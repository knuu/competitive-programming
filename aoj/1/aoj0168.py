dp = [0] * 34
dp[0] = 1
for i in range(30):
    dp[i+1] += dp[i]
    dp[i+2] += dp[i]
    dp[i+3] += dp[i]
while True:
    n = input()
    if n == 0: break
    print(dp[n]//3650+1)
