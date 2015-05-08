from math import hypot
N = int(input())

def isOverlap(x1, y1, x2, y2, r=10):
    return hypot(x1-x2, y1-y2) < r * 2

def check(x, y):
    near = [(-1, -1), (0, -1), (1, -1),
            (-1, 0), (0, 0), (1, 0),
            (-1, 1), (0, 1), (1, 1)]
    for dx, dy in near:
        nx = x//20 + dx
        ny = y//20 + dy
        if 0 <= nx <= 1000 and 0 <= ny <= 1000:
            for cx, cy in field[nx][ny]:
#                print(x, y, nx, ny, cx, cy, isOverlap(x, y, cx, cy))
                if isOverlap(x, y, cx, cy):
                    return False
    return True
            

field = [[[] for _ in range(1001)] for _ in range(1001)]
ans = 0
for _ in range(N):
    x, y = map(int, input().split())
    if check(x, y):
        ans += 1
        field[x//20][y//20].append((x, y))    
print(ans)
