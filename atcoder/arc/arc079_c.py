N = int(input())
A = [int(x) for x in input().split()]
ans = 0
while True:
    max_A = max(A)
    if max_A < N:
        break
    S = sum(a // N for a in A)
    ans += S
    for i in range(N):
        A[i] = A[i] - (A[i] // N) * N + (S - (A[i] // N))
print(ans)
