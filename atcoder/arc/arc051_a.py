x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())
def dist(xa, ya, xb, yb):
    return (xa - xb) ** 2 + (ya - yb) ** 2
print('YES' if any(x < x2 or x3 < x or y < y2 or y3 < y for x, y in [(x1, y1+r), (x1+r, y1), (x1, y1-r), (x1-r, y1)]) else 'NO')
print('YES' if any(dist(x, y, x1, y1) >= r**2 for x, y in [(x2, y2), (x2, y3), (x3, y2), (x3, y3)]) else 'NO')
