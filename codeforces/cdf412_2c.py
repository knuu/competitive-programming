def ceil(x, y):
    return x // y + (x % y != 0)

for _ in range(int(input())):
    x, y, p, q = map(int, input().split())
    if p == 0:
        print(0 if x == 0 else -1)
    elif p == q:
        print(0 if x == y else -1)
    else:
        k = max(ceil(y * q - q * x, q * (q - p)), ceil(x, p))
        # print(k, end=':')
        a = k * p - x
        b = k * q - (a + y)
        # print(a, b, a + b)
        print(a + b)
