def main():
    H, W = map(int, input().split())
    board = [[int(s == ".") for s in input()] for _ in range(H)]
    mod = 10 ** 9 + 7
    dp = [[0] * (W+1) for _ in range(H+1)]
    dp[0][0] = 1
    for i in range(H):
        for j in range(W):
            if board[i][j]:
                dp[i][j] %= mod
            else:
                dp[i][j] = 0
            dp[i+1][j] += dp[i][j]
            dp[i][j+1] += dp[i][j]
    print(dp[H-1][W-1])


if __name__ == '__main__':
    main()
