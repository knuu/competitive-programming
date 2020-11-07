R, C = map(int, input().split())
ans = 0
drc = [(0, 0), (C, 0), (0, C), (C, C)]
for i in range(0, R, C):
    for j in range(0, R, C):
        if all((i + dr) ** 2 + (j + dc) ** 2 <= R ** 2 for dr, dc in drc):
            ans += 1
print(ans * 4)
