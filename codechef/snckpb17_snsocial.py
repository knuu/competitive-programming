drc = [(-1, -1), (-1, 0), (-1, 1),
       (0, -1), (0, 1),
       (1, -1), (1, 0), (1, 1)]


def in_board(r, c):
    return 0 <= r < N and 0 <= c < M


for _ in range(int(input())):
    N, M = map(int, input().split())
    board = [[int(x) for x in input().split()] for _ in range(N)]
    max_val = max(max(row) for row in board)
    now = [(r, c) for r, row in enumerate(board) for c, col in enumerate(row) if col == max_val]
    cnt = 0
    while True:
        nex = []
        for r, c in now:
            for dr, dc in drc:
                nr, nc = r + dr, c + dc
                if in_board(nr, nc) and board[nr][nc] < max_val:
                    board[nr][nc] = max_val
                    nex.append((nr, nc))
        if nex:
            cnt += 1
            now = nex
        else:
            break
    print(cnt)
