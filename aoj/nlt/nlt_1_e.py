def extgcd(a, b):
    """solve ax + by = gcd(a, b)
       return x, y, gcd(a, b)
       unproved
    """
    g = a
    if b == 0:
        x, y = 1, 0
    else:
        x, y, g = extgcd(b, a % b)
        x, y = y,  x - a // b * y
    return x, y, g

a, b = map(int, input().split())
print(*extgcd(a, b)[:2])
