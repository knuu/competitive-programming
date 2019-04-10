from itertools import cycle

K = int(input())
Y, X = map(int, input().split())
board = []
str_iter = cycle("yfkpo")
for i in range(Y):
    row = []
    for j in range(K):
        row.append(next(str_iter))
    if i % 2 == 0:
        board.append(row)
    else:
        board.append(row[::-1])
print(board[Y - 1][X - 1])
