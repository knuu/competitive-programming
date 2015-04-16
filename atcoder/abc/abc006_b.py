n = int(input())
a = [0, 0, 1]
if n <= 3:
    print(a[n-1])
    exit(0)

mod = 10 ** 4 + 7
for _ in range(3, n):
    a[0], a[1], a[2] = a[1] % mod, a[2] % mod, (a[0] + a[1] + a[2]) % mod
print(a[2])
