from fractions import gcd
N, K = map(int, input().split())
A = [int(x) for x in input().split()]
min_A, max_A = min(A), max(A)
g = A[0]
for i in range(1, N):
    g = gcd(g, A[i])
if max_A < K:
    print("IMPOSSIBLE")
else:
    print("POSSIBLE" if K % g == 0 else "IMPOSSIBLE")
