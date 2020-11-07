def main():
    (N, K) = map(int, input().split())
    H = [int(x) for x in input().split()]
    dp = [0] * N
    for i in range(1, N):
        ret = 10 ** 18
        for j in range(K):
            if i - 1 - j < 0:
                break
            ret = min(ret, dp[i-1-j] + abs(H[i] - H[i-1-j]))
        dp[i] = ret
    print(dp[-1])


if __name__ == '__main__':
    main()
