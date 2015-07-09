n, m = map(int, input().split())
board = [input() for i in range(n)]
ans = 0
for i in range(n-1):
    for j in range(m-1):
        s = [board[i][j], board[i+1][j], board[i][j+1], board[i+1][j+1]]
        if 'f' in s and 'a' in s and 'c' in s and 'e' in s:
            ans += 1
print(ans)
