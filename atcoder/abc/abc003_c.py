N, K = map(int, input().split())
R = sorted(map(int, input().split()))
ans = 0
for r in R[len(R)-K:]:
    ans = (ans + r) / 2
print(ans)
