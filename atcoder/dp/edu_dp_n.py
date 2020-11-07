def main():
    N = int(input())
    A = [int(a) for a in input().split()]
    INF = 10 ** 18
    dp = [[INF] * N for _ in range(N)]
    for i in range(N):
        dp[i][i] = 0
    acc = [0]
    for a in A:
        acc.append(acc[-1] + a)
    for w in range(2, N+1):
        for left in range(N):
            right = left + w - 1
            if right >= N:
                continue
            wsum = acc[right + 1] - acc[left]
            for mid in range(left, right):
                dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid+1][right] + wsum)
    print(dp[0][N-1])


if __name__ == '__main__':
    main()
