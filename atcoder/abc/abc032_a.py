from fractions import gcd
from math import ceil

a, b, n = int(input()), int(input()), int(input())
g = gcd(a, b)
gcm = (a // g) * (b // g) * g
print(int(ceil(n / gcm)) * gcm)
