def main():
    N = int(input())
    dp = [[0] * 3 for _ in range(2)]
    for i in range(N):
        a, b, c = map(int, input().split())
        now_i, next_i = i & 1, (i+1) & 1
        dp[next_i][0] = max(dp[now_i][1], dp[now_i][2]) + a
        dp[next_i][1] = max(dp[now_i][0], dp[now_i][2]) + b
        dp[next_i][2] = max(dp[now_i][0], dp[now_i][1]) + c
    print(max(dp[N & 1]))


if __name__ == '__main__':
    main()
