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

def convert_base(num, base):
    converted = []
    while num:
        num, r = divmod(num, base)
        converted.append(r)
    return converted

def solve(w, m):
    m_w = convert_base(m, w)
    m_w +=  [0] * (101-len(m_w))
    for i in range(101):
        if m_w[i] == 0 or m_w[i] == 1:
            continue
        elif m_w[i] == w or m_w[i] == w-1:
            m_w[i+1] += 1
        else:
            return False
    return True

w, m = read_list(int)
print('YES' if solve(w, m) else 'NO')



