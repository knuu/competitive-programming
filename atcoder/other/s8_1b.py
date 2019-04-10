H, W, N = map(int, input().split())
berry = [tuple(int(x) for x in input().split()) for _ in range(N)]
ans = []
for i in range(1, W+1):
    up = 0
    for x, y in berry:
        if i * y == H * x:
            break
        elif i * y > H * x:
            up += 1
    else:
        if up * 2 == N:
            ans.append((i, H))
for i in range(1, H):
    up = 0
    for x, y in berry:
        if W * y == i * x:
            break
        elif W * y > i * x:
            up += 1
    else:
        if up * 2 == N:
            ans.append((W, i))
ans.sort()
if ans:
    for x, y in ans:
        print('({},{})'.format(x, y))
else:
    print(-1)
