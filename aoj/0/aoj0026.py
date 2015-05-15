board = [[0]*10 for _ in range(10)]
while True:
    try:
        x, y, size = map(int, input().split(','))
    except:
        break
    small = [(-1, 0), (0, -1), (0, 0), (0, 1), (1, 0)]
    med = [(-1, -1), (-1, 0), (-1, 1),
           (0, -1), (0, 0), (0, 1),
           (1, -1), (1, 0), (1, 1)]
    large = [(-2, 0),
             (-1, -1), (-1, 0), (-1, 1),
             (0, -2), (0, -1), (0, 0), (0, 1), (0, 2),
             (1, -1), (1, 0), (1, 1),
             (2, 0)]
    dyx = [small, med, large][size-1]
    for dy, dx in dyx:
        ny, nx = y + dy, x + dx
        if 0 <= nx < 10 and 0 <= ny < 10:
            board[ny][nx] += 1

print(sum(sum(1 for i in range(10) if row[i] == 0) for row in board))
print(max([max(row) for row in board]))
