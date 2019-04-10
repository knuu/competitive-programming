N = int(input())
points = [tuple(int(x) for x in input().split()) for _ in range(N)]
if any(abs(x + y) % 2 != abs(sum(points[0])) % 2 for x, y in points):
    print(-1)
    quit()
if any(not (-10 <= x <= 10 and -10 <= y <= 10) for x, y in points):
    assert False

M = 20 + (abs(sum(points[0])) % 2)
print(M)
print(*[1] * M)
for x, y in points:
    print("LR"[x > 0] * abs(x) + "DU"[y > 0] * abs(y) + "DU" * ((M - abs(x) - abs(y)) // 2))
