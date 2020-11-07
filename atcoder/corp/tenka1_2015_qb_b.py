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
argmax = lambda l: l.index(max(l))
argmin = lambda l: l.index(min(l))

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

S = read_line(str)
N = len(S)

if S == '{}':
    print('dict')
    exit(0)
i = 1
if S[i] == '{':
    par = 1
    i += 1
    while i < N and par:
        if S[i] == '{':
            par += 1
        elif S[i] == '}':
            par -= 1
        i += 1
elif S[i] in digits:
    while i < N and S[i] in digits:
        i += 1
if S[i] == ':':
    print('dict')
else:
    print('set')
