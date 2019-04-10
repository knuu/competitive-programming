l, r, k = map(int, input().split())
n = 1
ans = []
while n <= r:
    if l <= n <= r:
        ans.append(n)
    n *= k
if ans:
    print(*ans)
else:
    print(-1)
