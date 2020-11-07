def main():
    N = int(input())
    P = [float(x) for x in input().split()]
    over = (N + 1) // 2
    dp = [[0.0] * (over + 1) for _ in range(N + 1)]
    dp[0][0] = 1.0
    for i in range(N):
        for j in range(over):
            dp[i+1][j] += dp[i][j] * (1 - P[i])
            dp[i+1][j+1] += dp[i][j] * P[i]
        dp[i+1][over] += dp[i][over]
    print("{:.20f}".format(dp[-1][-1]))


if __name__ == '__main__':
    main()
