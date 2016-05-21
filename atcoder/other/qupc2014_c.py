R, C, Q = map(int, input().split())
board = [input() for _ in range(R)]
query = [input() for _ in range(Q)]
pos = dict()
for r, row in enumerate(board):
    for c, s in enumerate(row):
        if s != '*':
            pos[s] = (r+1, c+1)
for q in query:
    if q in pos:
        print(*pos[q])
    else:
        print('NA')
