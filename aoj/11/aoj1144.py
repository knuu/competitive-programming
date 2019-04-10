import collections
import copy
import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
drc = [(0, -1), (1, 0), (0, 1), (-1, 0)]


def in_board(r, c):
    return 0 <= r < H and 0 <= c < W


def bfs(origin_board):
    sr, sc, gr, gc = 0, 0, 0, 0
    for r in range(H):
        for c in range(W):
            if origin_board[r][c] == 2:
                sr, sc = r, c
            elif origin_board[r][c] == 3:
                gr, gc = r, c
    origin_board[sr][sc] = origin_board[gr][gc] = 0
    que = collections.deque([(sr, sc, origin_board, 0)])
    while que:
        r, c, board, cnt = que.popleft()
        if cnt == 10:
            continue
        for dr, dc in drc:
            nr, nc = r + dr, c + dc
            if in_board(nr, nc) and board[nr][nc] != 1:
                next_board = copy.deepcopy(board)
                while in_board(nr, nc) and board[nr][nc] == 0:
                    if (nr, nc) == (gr, gc):
                        return cnt + 1
                    nr += dr
                    nc += dc
                if in_board(nr, nc) and cnt < 9:
                    next_board[nr][nc] = 0
                    que.append((nr - dr, nc - dc, next_board, cnt + 1))
    return -1


while True:
    W, H = map(int, input().split())
    if not (W | H):
        break
    origin_board = [[int(x) for x in input().split()] for _ in range(H)]
    print(bfs(origin_board))
