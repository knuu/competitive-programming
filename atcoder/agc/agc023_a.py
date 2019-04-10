from collections import Counter
N = int(input())
A = [int(x) for x in input().split()]
for i in range(N - 1):
    A[i + 1] += A[i]
A = Counter(A)
ans = 0
for k, v in A.items():
    ans += v * (v - 1) // 2
    if k == 0:
        ans += v
print(ans)
