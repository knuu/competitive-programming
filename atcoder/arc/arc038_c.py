from queue import Queue
from queue import PriorityQueue as PQueue
from queue import LifoQueue as Stack
from collections import Counter, defaultdict, deque, OrderedDict

from sys import setrecursionlimit as setreclim
from sys import maxsize
from bisect import bisect_left, bisect, insort_left, insort
import math
from fractions import gcd
from copy import deepcopy
from functools import reduce
from itertools import * 
import string        

# get 100 points, but TLE in some samples
# TODO: Segment Tree

N = int(input())
C = [0]
A = [0]
for i in range(N-1):
    c, a = map(int, input().split())
    C.append(c); A.append(a)
G = [0] * N
def grundy(n):
    g = [0] * N
    for i in range(n-C[n], n):
        g[G[i]] += 1
    return g.index(0)

for i in range(1, N):
    G[i] = grundy(i)
nim = 0
for g, a in zip(G, A):
    if a % 2 == 1:
        nim ^= g
print('First' if nim != 0 else 'Second')
