import sys
sys.setrecursionlimit(3000)
def dfs(r, c, n):
    board[r][c] = n
    drc = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    for dr, dc in drc:
        nr, nc = r + dr, c + dc
        if 0 <= nr < h and 0 <= nc < w and board[nr][nc] != n:
            if board[nr][nc] in 'WB':
                pile.append(board[nr][nc])
                continue
            dfs(nr, nc, n)

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0: break
    board = [list(input()) for _ in range(h)]
    place = 0
    piles = []
    black, white = [], []
    for r in range(h):
        for c in range(w):
            if board[r][c] == '.':
                pile = []
                place += 1
                dfs(r, c, place)
                piles.append(pile)

    for i, pile in enumerate(piles):
        if not pile: continue
        if all(p == 'B' for p in pile):
            black.append(i+1)
        elif all(p == 'W' for p in pile):
            white.append(i+1)

    ans_b, ans_w = 0, 0
    for row in board:
        for c in row:
            if c in black:
                ans_b += 1
            elif c in white:
                ans_w += 1
    print(ans_b, ans_w)
