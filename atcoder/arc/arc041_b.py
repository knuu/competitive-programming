range = xrange
input = raw_input

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N, M = read_list(int)
board = [[int(x) for x in row] for row in read_lines(list, N)]


ans = [[0]*M for _ in range(N)]
drc = [(-1, 0), (0, 1), (1, 0), (0, -1)]
for r in range(1, N-1):
    for c in range(1, M-1):
        ameba = 10
        for dr, dc in drc:
            ameba = min(ameba, board[r+dr][c+dc])
        for dr, dc in drc:
            board[r+dr][c+dc] -= ameba
        ans[r][c] = ameba
for row in ans:
    print ''.join(map(str, row))
