N, X, Y, Z = map(int, input().split())
ans = 0
for _ in range(N):
    a, b = map(int, input().split())
    ans += a >= X and b >= Y and a + b >= Z
print(ans)
