def main():
    K = input()
    D = int(input())
    L = len(K)
    dp = [[[0, 0] for _ in range(D)] for _ in range(L+1)]
    mod = 10 ** 9 + 7
    dp[0][0][1] = 1
    for i in range(L):
        d = int(K[i])
        for j in range(D):
            for k in range(10):
                dp[i+1][(j + k) % D][0] += dp[i][j][0]
                dp[i+1][(j + k) % D][0] %= mod
                if k < d:
                    dp[i+1][(j + k) % D][0] += dp[i][j][1]
                    dp[i+1][(j + k) % D][0] %= mod
                elif k == d:
                    dp[i+1][(j + k) % D][1] += dp[i][j][1]
                    dp[i+1][(j + k) % D][1] %= mod
    print((sum(dp[-1][0]) + mod - 1) % mod)


if __name__ == '__main__':
    main()
