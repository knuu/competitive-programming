n = int(input())
R = [int(input()) for _ in range(n)]
ans = R[1] - R[0]
bottom = min(R[0], R[1])
for r in R[2:]:
    ans = max(ans, r - bottom)
    if r < bottom:
        bottom = r
print(ans)
