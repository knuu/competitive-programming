r, c, m = map(int, input().split())
n = int(input())
op = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(n)]
board = [[0 for _ in range(c)] for _ in range(r)]

for ra, rb, ca, cb in op:
    for j in range(ra, rb + 1):
        for k in range(ca, cb + 1):
            board[j][k] += 1
cnt = 0
for i in range(r):
    for j in range(c):
        board[i][j] %= 4
        if board[i][j] == 0:
            cnt += 1

for i in range(n):
    ra, rb, ca, cb = op[i]
    cnti = cnt
    for j in range(ra, rb + 1):
        for k in range(ca, cb + 1):
            if board[j][k] == 0:
                cnti -= 1
            elif board[j][k] == 1:
                cnti += 1
    if cnti == m:
        print(i + 1)
