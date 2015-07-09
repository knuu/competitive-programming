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

T = read_line(int)
for _ in range(T):
    R, S = read_list(int)
    k = R // S
    if S * k <= R <= S * k + S // 4:
        g = gcd(R-S*k, S)
        print('{} {}/{}'.format(R, (R-S*k)//g, S//g))
    else:
        print('{} 0/1'.format(S*(k+1)))
