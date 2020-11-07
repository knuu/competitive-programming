

H, W, K, V = map(int, input().split())

board = [[0] * (W + 1)]
for _ in range(H):
    row = [0] + [int(x) for x in input().split()]
    board.append(row)
for r in range(H+1):
    for c in range(W):
        board[r][c+1] += board[r][c]
for c in range(W+1):
    for r in range(H):
        board[r+1][c] += board[r][c]

ans = 0
for r1 in range(H):
    for c1 in range(W):
        for r2 in range(r1, H):
            for c2 in range(c1, W):
                sq = board[r2+1][c2+1] - board[r2+1][c1] - board[r1][c2+1] + board[r1][c1]
                height, width = r2 - r1 + 1, c2 - c1 + 1
                cost = height * width * K + sq
                if cost <= V and height * width > ans:
                    ans = height * width
print(ans)
