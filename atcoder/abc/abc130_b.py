N, X = map(int, input().split())
ans = 1
now = 0
for l in map(int, input().split()):
    now += l
    if now <= X:
        ans += 1
print(ans)
