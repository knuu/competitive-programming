def up(r, c):
    assert(board[r][c] == 'W')
    ans = r
    while r >= 0:
        if board[r][c] == 'B':
            return 9
        r -= 1
    else:
        return ans


def down(r, c):
    assert(board[r][c] == 'B')
    ans = 7 - r
    while r < 8:
        if board[r][c] == 'W':
            return 9
        r += 1
    else:
        return ans

white, black = 9, 9
board = [input() for _ in range(8)]

for r in range(8):
    for c in range(8):
        if board[r][c] == 'W':
            white = min(white, up(r, c))
        elif board[r][c] == 'B':
            black = min(black, down(r, c))
assert(white != 9 or black != 9)
print('A' if white <= black else 'B')
