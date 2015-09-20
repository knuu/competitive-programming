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

class Prime:
    """ make prime numbers lists
        complexity: O(n^(1/2))
        used in AOJ0202
    """

    def __init__(self, n):
        self.is_prime = [True for _ in range(n+1)]
        self.primeList = []
        self.is_prime[0] = self.is_prime[1] = False
        for i in range(2, int(pow(n, 0.5))+1):
            if self.is_prime[i] == True:
                self.primeList.append(i)
                for j in range(2*i, n+1, i):
                    self.is_prime[j] = False
        for i in range(int(pow(n, 0.5))+1, n+1):
            if self.is_prime[i] == True:
                self.primeList.append(i)

    def isPrime(self, n):
        return self.is_prime[n]

    def nthPrime(self, n):
        return self.primeList[n-1]

N = read_line(int)
p = Prime(N)
ans = []
for i in range(2, N+1):
    if p.isPrime(i):
        now = i
        while now <= N:
            ans.append(now)
            now *= i
print(len(ans))
if len(ans) > 0:
    print(*ans)


