from itertools import combinations
n, l, r, x = map(int, input().split())
C = list(map(int, input().split()))
ans = 0
for i in range(2, n+1):
    for c in combinations(C, i):
        s = sum(c)
        if s < l or r < s:
            continue
        if max(c) - min(c) < x:
            continue
        ans += 1
print(ans)
