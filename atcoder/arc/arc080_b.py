H, W = map(int, input().split())
N = int(input())
A = [int(x) for x in input().split()]
board = [[0] * W for _ in range(H)]
colors = [i + 1 for i in range(N) for _ in range(A[i])]

for i in range(H):
    if i % 2 == 0:
        for j in range(W):
            board[i][j] = colors[i * W + j]
    else:
        for j in range(W):
            board[i][W-j-1] = colors[i * W + j]
for row in board:
    print(*row)
