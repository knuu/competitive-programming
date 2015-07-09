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

exp = read_line(str)
len_exp = len(exp)
ans = eval(exp)
mul_p = [i for i, s in enumerate(exp) if s == '*']
mul_p = [-1] + mul_p + [len(exp)]
for i1, i2 in combinations(mul_p, 2):
    ans = max(ans, eval('{}({}){}'.format(exp[:i1+1], exp[i1+1:i2], exp[i2:])))
print(ans)
        



    
