n = int(input())
v, f = [list(map(int, input().split())) for x in range(2)]
cnt = 0
for i in range(n):
    if v[i] // 2 < f[i]: cnt += 1

print(cnt)
