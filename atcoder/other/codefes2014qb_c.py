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

S1, S2, S3 = read_line(str), read_line(str), read_line(str)
c1, c2, c3 = Counter(S1), Counter(S2), Counter(S3)

N = len(S1) // 2
min_s1, min_s2 = 0, 0 # 最低限必要となる個数
for key, val in c3.items():
    n1, n2 = c1[key], c2[key]
    if n1 + n2 < val:
        print('NO')
        exit(0)
    min_s1 += max(0, val-n2)
    min_s2 += max(0, val-n1)
    if min_s1 > N or min_s2 > N:
        print('NO')
        exit(0)
print('YES')
