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

N = read_line(int)
array = read_list(int)
i = 0
inc_subsegments = []
while i < N:
    start = i
    while i+1 < N and array[i] < array[i+1]:
        i += 1
    if i != start:
        inc_subsegments.append((start, i))
    i += 1
ans = max(min(2, N), max(min(end-start+1+1, N) for start, end in inc_subsegments) if inc_subsegments else 0)

for i in range(len(inc_subsegments) - 1):
    i_last = inc_subsegments[i][1]
    i_next_first = inc_subsegments[i+1][0]
    if i_last + 1 == i_next_first and (array[i_next_first + 1] - array[i_last] > 1 or array[i_next_first] - array[i_last - 1] > 1):
        ans = max(ans, inc_subsegments[i+1][1] - inc_subsegments[i][0] + 1)
print(ans)
