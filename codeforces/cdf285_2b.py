q = int(input())
logs = [input().split() for _ in range(q)]
origin = []
now = []
cnt = 0
for old, new in logs:
    if old not in now:
        origin.append(old)
        now.append(new)
        cnt += 1
    else:
        now[now.index(old)] = new
print(cnt)
for i in range(len(now)):
    print(origin[i], now[i])
