def in_(x, y):
    return -x + y >= -N * K and x + y >= N * K and x + y <= 3 * K * N and -x + y <= N * K

N = int(input())
ans = 0
K = 100
for i in range(N):
    for j in range(N):
        a, b = i * 2 * K, (i + 1) * 2 * K
        c, d = j * 2 * K, (j + 1) * 2 * K
        if in_(a, c) and in_(a, d) and in_(b, c) and in_(b, d):
            ans += 1
print(ans)
