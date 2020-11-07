import sys
import math
if sys.version_info.minor >= 5:
    from math import gcd
else:
    from fractions import gcd


def inv(x, mod):
    return pow(x, mod-2, mod)


def lcm(arr, mod = 10 ** 9 + 7):
    ret = 1
    for a in arr:
        ret = ret * a // gcd(ret, a)
    return ret

mod = 10 ** 9 + 7

N = int(input())
A = [int(x) for x in input().split()]
a = lcm(A)
print(sum(a // x for x in A) % mod)
