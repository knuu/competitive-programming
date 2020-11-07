deg = [0] * 4
for _ in range(3):
    a, b = map(int, input().split())
    deg[a - 1] += 1
    deg[b - 1] += 1
if all(x <= 2 for x in deg):
    print("YES")
else:
    print("NO")
