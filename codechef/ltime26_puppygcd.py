from fractions import gcd
for _ in range(int(input())):
    N, D = map(int, input().split())
    ans = 0
    for i in range(D, N+1):
        for j in range(i, N+1):
            ans += gcd(i, j) == D
    print(ans)
