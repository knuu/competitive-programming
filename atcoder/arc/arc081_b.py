N = int(input())
board = [input(), input()]
dp = [[[0] * 3 for _ in range(N)] for _ in range(2)]
mod = 10 ** 9 + 7
for i in range(3):
    dp[0][0][i] = 1
if board[0][0] == board[1][0]:
    for i in range(3):
        dp[1][0][i] = 1
else:
    for i in range(3):
        dp[1][0][i] = 2
for j in range(N - 1):
    for i in range(2):
        if board[i][j] == board[i][j + 1]:
            for k in range(3):
                dp[i][j + 1][k] = dp[i][j][k]
        elif i == 1 and board[i][j] == board[i - 1][j]:
            for k in range(3):
                dp[i][j][k] = dp[i - 1][j][k]
        for k in range(3):
            if board[i][j] == board[i][j + 1]:
                dp[i][j + 1][k] = dp[i][j][k]
            elif i == 1 and board[i][j + 1] == board[i - 1][j + 1]:
                dp[i][j][k] = dp[i - 1][j][k]
            elif i == 0 and board[i][j + 1] == board[i + 1][j + 1]:
                for l in range(3):
                    for h in range(3):
                        if l != k and h != k and l != h:
                            dp[i][j + 1][k] += dp[i][j][l] * dp[i + 1][
                dp[i][j + 1][k] = (sum(dp[i][j]) - dp[i][j][k] + mod) % mod
            else:
                dp[i][j + 1][k] = (sum(dp[i][j]) - dp[i][j][k] + mod) % mod * (sum(dp[i - 1][j]) - dp[i - 1][j][k] + mod) % mod
            print(i, j + 1, k, ':', dp[i][j + 1][k])
print(sum(dp[1][N - 1]) % mod)
