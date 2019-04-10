N, K = map(int, input().split())
A = [int(x) for x in input().split()]
min_idx = A.index(1)
if min_idx < K:
    min_idx = K - 1
elif min_idx >= N - K:
    min_idx = N - K
ans = min_idx // (K - 1) + (N - min_idx - 1) // (K - 1)
if min_idx % (K - 1) != 0:
    ans += 1
if (N - min_idx - 1) % (K - 1) != 0:
    ans += 1
print(ans)
