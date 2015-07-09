while True:
    N = int(input())
    if not N: break
    cells = [[int(x) for x in input().split()] for _ in range(N)]
    point = 0
    while True:
        flag = False
        for i, cell in enumerate(cells):
            j = 0
            while j < 5:
                s, color = j, cell[j]
                while j < 5 and cell[j] == color:
                    j += 1
                if color != 0 and j - s >= 3:
                    point += color * (j - s)
                    cell[s:j] = [0] * (j-s)
                    flag = True
        for i in range(5):
            for j in reversed(range(N)):
                s = j
                while s >= 0 and not cells[s][i]:
                    s -= 1
                if s >= 0:
                    cells[j][i], cells[s][i] = cells[s][i], cells[j][i]
        if not flag:
            break
    print(point)
