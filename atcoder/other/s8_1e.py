N, Q = map(int, input().split())
A = [int(x) for x in input().split()]
C = [0] + [int(x)-1 for x in input().split()] + [0]
ans = 0
mod = 10**9 + 7
go = [0] + [pow(A[i], A[i+1], mod) for i in range(N-1)]

for i in range(N):
    go[i+1] += go[i]

c = len(C)
ans = 0
for i in range(c-1):
    c, n = C[i], C[i+1]
    if c < n:
        ans += go[n] - go[c]
    else:
        ans += go[c] - go[n]
    ans %= mod
print(ans)
