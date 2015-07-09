from heapq import heapify, heappush, heappop
from collections import Counter, defaultdict, deque, OrderedDict
from sys import setrecursionlimit, maxsize
from bisect import bisect_left, bisect, insort_left, insort
from math import ceil, log, factorial, hypot, pi
from fractions import gcd
from copy import deepcopy
from functools import reduce
from operator import mul
from itertools import product, permutations, combinations, accumulate, cycle
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits

prod = lambda l: reduce(mul, l)
prodmod = lambda l, mod: reduce(lambda x, y: mul(x,y)%mod, l)

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

mod = 10**9+7
def inv(x):
    return pow(x, mod-2, mod)

K = read_line(int)
balls = read_lines(int, K)

s = balls[0]
ans = 1
for ball in balls[1:]:
    ans *= ball
    ans %= mod
    for i in range(s+1, s+ball):
        ans *= i
        ans %= mod
    for i in range(ball):
        ans *= inv(i+1)
        ans %= mod
    s += ball
print(ans)
