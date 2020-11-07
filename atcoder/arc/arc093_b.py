A, B = map(int, input().split())

N = 100
board = [['.#'[row >= N//2] for _ in range(N)] for row in range(N)]
for i in range(B-1):
    r, c = i // 25 * 2, (i % 25) * 2
    board[r][c] = "#"
for i in range(A-1):
    r, c = i // 25 * 2, (i % 25) * 2
    board[-r-1][c] = "."
print(N, N)
print("\n".join(''.join(row) for row in board))
