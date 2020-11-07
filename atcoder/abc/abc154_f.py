mod = 10 ** 9+7


def inv(x):
    return pow(x, mod - 2, mod)


r1, c1, r2, c2 = map(int, input().split())
fact, inv_fact = [1, 1], [1, 1]
for i in range(2, r2+c2+3):
    fact.append(fact[-1] * i % mod)
    inv_fact.append(inv(fact[-1]))


def nCr(n, r):
    return fact[n] * inv_fact[r] * inv_fact[n-r] % mod


def path_sum_sum(r, c):
    return ((r + 2) * nCr(c+r+2, r+2) % mod + mod - c - 1) * inv(c + 1) % mod


ans = (path_sum_sum(r2, c2) + mod - path_sum_sum(r2, c1-1) +
       mod - path_sum_sum(r1-1, c2) + path_sum_sum(r1-1, c1-1))
print(ans % mod)
