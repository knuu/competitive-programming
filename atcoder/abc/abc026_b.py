from itertools import cycle
from math import pi
N = int(input())
rad = sorted([int(input()) for _ in range(N)], reverse=True)
print(sum(sig * (r ** 2) for sig, r in zip(cycle([1, -1]), rad)) * pi)
    
