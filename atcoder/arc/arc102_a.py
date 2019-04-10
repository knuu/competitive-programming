N, K = map(int, input().split())
ans = 0
for i in range(1, N + 1):
    x = i % K
    if 2 * (K - x) % K == 0:
        ans += ((N + x) // K) ** 2
print(ans)
