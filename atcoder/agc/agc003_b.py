N = int(input())
A = [int(input()) for _ in range(N)]

ans, cnt = 0, 0
for a in A:
    if a == 0:
        ans += cnt // 2
        cnt = 0
    else:
        cnt += a
ans += cnt // 2
print(ans)
