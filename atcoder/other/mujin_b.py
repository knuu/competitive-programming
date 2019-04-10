from math import acos
a, b, c = sorted(map(int, input().split()))
r = a + b + c
if c <= a + b:
    print(acos(-1) * r ** 2)
else:
    print((r ** 2 - (c - a - b) ** 2) * acos(-1))
