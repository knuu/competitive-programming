from math import pi
C = int(input())
Rin, Rout = map(int, input().split())
r = (Rout - Rin)/2
print(r * r * pi * 2 * (Rin + r) * pi * C)
