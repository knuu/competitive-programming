N = int(input())
points = []
x_set = set()
y_set = set()
for _ in range(N):
    x, y = map(int, input().split())
    x_set.add(x-y)
    y_set.add(x+y)
    points.append((x, y))
x_min, x_max = min(x_set), max(x_set)
y_min, y_max = min(y_set), max(y_set)
L = max(x_max - x_min, y_max - y_min) // 2

cands = [
    (x_min + L, y_min + L),
    (x_min + L, y_max - L),
    (x_max - L, y_min + L),
    (x_max - L, y_max - L),
]


def dist_l1(p1, p2):
    return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])


for xx, yy in cands:
    x_mid, y_mid = (xx + yy) // 2, (-xx + yy) // 2
    p_mid = x_mid, y_mid
    if x_mid < -1e9 or 1e9 < x_mid or y_mid < -1e9 or 1e9 < y_mid:
        continue
    dist = dist_l1(p_mid, points[0])
    if all(dist_l1(p_mid, point) == dist for point in points):
        print(*p_mid)
        quit()
