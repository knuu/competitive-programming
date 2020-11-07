mod = 998244353
N = int(input())
ds = [0] * N
max_D = 0

for d in map(int, input().split()):
    ds[d] += 1
    max_D = max(max_D, d)
if ds[0] != 1:
    print(0)
    quit()
if any(ds[i] == 0 for i in range(1, max_D + 1)):
    print(0)
    quit()

ans = 1
for d in range(1, max_D + 1):
    ans *= pow(ds[d-1], ds[d], mod)
    ans %= mod
print(ans)
