import sys
if sys.version_info.major >= 3 and sys.version_info.minor >= 5:
    from math import gcd
else:
    from fractions import gcd


def calc_anti(N, C, D):
    lcm = C * D // gcd(C, D)
    div = N // C + N // D - N // lcm
    return N - div


A, B, C, D = map(int, input().split())
print(calc_anti(B, C, D) - calc_anti(A-1, C, D))
