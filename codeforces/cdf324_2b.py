N = int(input())
mod = 10**9+7
print((pow(3, 3*N, mod) - pow(7, N, mod)) % mod)
