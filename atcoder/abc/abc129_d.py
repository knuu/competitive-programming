import sys
if sys.version[0] == '2':
    input, range = raw_input, xrange
import numpy as np
H, W = map(int, input().split())
B = [input() for _ in range(H)]
board = np.zeros((H, W), dtype=int)
for r, row in enumerate(B):
    for c, col in enumerate(row):
        board[r][c] = 1 if col == "." else 0
cnt = np.zeros((H, W), dtype=int)
cnt[:, :] = 1

for _ in range(4):
    R, C = cnt.shape
    for c in range(C):
        now = 0
        for r in range(R):
            if board[r][c]:
                cnt[r][c] += now
                now += 1
            else:
                now = 0
    board = np.rot90(board, k=-1)
    cnt = np.rot90(cnt, k=-1)
print(cnt)
print(np.max(cnt))
