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

def miller_rabin(n):
    """ primality Test
        if n < 3,825,123,056,546,413,051, it is enough to test 
        a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
        Complexity: O(log^3 n)
    """
    if n == 2: return True
    if n <= 1 or not n&1: return False

    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

    d = n - 1
    s = 0
    while not d&1:
        d >>= 1
        s += 1

    for prime in primes:
        if prime >= n: continue
        x = pow(prime, d, n)
        if x == 1: break
        for r in range(s):
            if x == n - 1: break
            if r + 1 == s: return False
            x = x * x % n
    return True

N = read_line(int)
if miller_rabin(N) or (N != 1 and N % 2 != 0 and N % 5 != 0 and sum(map(int, list(str(N)))) % 3 != 0):
    print('Prime')
else:
    print('Not Prime')

