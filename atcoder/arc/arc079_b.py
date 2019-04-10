K = int(input())
L = 50
N = K // L + L - 1
res = K - (N - L + 1) * L
assert(res < 50)
ans = [N] * L
for i in range(res):
    ans[i] += L - res + 1
for i in range(res, L):
    ans[i] -= res
print(L)
print(*ans)
