N = int(input())
mod = 10 ** 9 + 7

A = [int(x) for x in input().split()]
ans = 0
for i in range(60):
    cnt = 0
    for a in A:
        cnt += a >> i & 1
    ans += cnt * (N - cnt) * (1 << i)
print(ans % mod)
