N = int(input())
def distSquare(x0, y0, x1, y1):
    return (x0 - x1) ** 2 + (y0 - y1) ** 2
points = [list(map(int, input().split())) for _ in range(N)]

from math import sqrt
distList = []
for i in range(N):
    xi, yi = points[i]
    for j in range(i+1, N):
        xj, yj = points[j]
        distList.append(distSquare(xi, yi, xj, yj))
print(sqrt(max(distList)))
