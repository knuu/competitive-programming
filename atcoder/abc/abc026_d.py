from math import pi, sin, cos

A, B, C = map(int, input().split())
f = lambda t: A * t + B * sin(C * t * pi) - 100
df = lambda t: A + B * C * pi * cos(C * t * pi)

#t = (100 - B) / A
t = 100 / A
while abs(f(t)) > 1e-6:
    t -= f(t) / df(t)
print(t)

"""
def f(t):
    return A * t + B * sin(C * t * pi)

left, right = 0, 1000
while abs(f(right) - 100) > 0.000001:
    mid = (right + left) / 2
#    print(left, right, f(mid))
    if f(mid) < 100:
        left = mid
    else:
        right = mid
print(right)
"""
