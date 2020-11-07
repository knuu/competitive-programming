N, M = map(int, input().split())
numset = set()
now = N
ans = 0
for _ in range(10 ** 5):
    mod = now % M
    if now % M in numset:
        break
    numset.add(mod)
    now += N
    ans = max((M - mod) % M, ans)

print(ans)
