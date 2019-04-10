N = int(input())
ans = 0
mod = 10**9 + 7

for i in range(1, N + 1):
    d = N // i
    ans += (pow(i, 10, mod) - pow(i - 1, 10, mod) + mod) * pow(d, 10, mod) % mod
    ans %= mod

print(ans)
