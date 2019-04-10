import itertools
from copy import deepcopy

row, col = list(range(8)), list(range(8))
board = [list(input()) for _ in range(8)]
plus, minus = set(), set()
for r in range(8):
    for c in range(8):
        if board[r][c] == 'Q':
            if r not in row or c not in col:
                print("No Answer")
                quit()
            row.remove(r)
            col.remove(c)
            plus.add(r+c)
            minus.add(r-c)
for l in itertools.permutations(col):
    plus_t, minus_t = deepcopy(plus), deepcopy(minus)
    for r, c in zip(row, l):
        plus_t.add(r+c)
        minus_t.add(r-c)
    if len(plus_t) == len(minus_t) == 8:
        for r, c in zip(row, l):
            board[r][c] = 'Q'
        print(*[''.join(row) for row in board], sep='\n')
        break
else:
    print("No Answer")
