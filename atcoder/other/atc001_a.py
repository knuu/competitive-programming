H, W = map(int, input().split())
board = [list(input()) for _ in range(H)]
sr, sc = [(i, row.index('s')) for i, row in enumerate(board) if 's' in row][0]
drc = [(-1, 0), (0, 1), (1, 0), (0, -1)]
stack = [(sr, sc)]
while stack:
    r, c = stack.pop()
    board[r][c] = 'x'
    for dr, dc in drc:
        nr, nc = r+dr, c+dc
        if 0 <= nr < H and 0 <= nc < W and board[nr][nc] in '.g':
            if board[nr][nc] == 'g':
                print('Yes')
                exit(0)
            else:
                stack.append((nr, nc))
print('No')
