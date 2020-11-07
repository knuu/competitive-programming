import sys
import math
if sys.version_info.minor >= 5:
    from math import gcd
else:
    from fractions import gcd

A, B = map(int, input().split())
g = gcd(A, B)
print(A * B // g)
