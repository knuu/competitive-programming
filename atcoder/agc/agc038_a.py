H, W, A, B = map(int, input().split())

board = [[0] * W for _ in range(H)]
for i in range(B):
    for j in range(A):
        board[i][j] = 1
for i in range(B, H):
    for j in range(A, W):
        board[i][j] = 1
assert all(sum(row) in [A, W-A] for row in board)
assert all(sum(board[i][j] for i in range(H)) in [B, H-B] for j in range(W))
for row in board:
    print("".join(map(str, row)))
