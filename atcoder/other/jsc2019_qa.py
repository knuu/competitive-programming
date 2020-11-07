M, D = map(int, input().split())

ans = 0
for m in range(2, M+1):
    for dd in range(11, D + 1):
        d1, d2 = map(int, str(dd))
        ans += d1 > 1 and d2 > 1 and d1 * d2 == m

print(ans)
