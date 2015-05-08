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

n, k, p, x, y = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
a.reverse()


if k >= n//2 + 1:
    med = a[n//2]
    if med >= y:
        testsum = sum(a) + 1*(n-k)
        print(-1 if testsum > x else ' '.join(['1' for _ in range(n-k)]))
    else:
        t = a.count(y)
        while len(a) < n and a[n//2] < y:
            a.append(y)
            a.sort()
            a.reverse()
        leny = a.count(y) - t
        len1 = n - len(a)
        a += [1 for _ in range(len1)]
        print(-1 if a[n//2] < y or sum(a) > x else ' '.join([str(y) for _ in range(leny)] + ['1' for _ in range(len1)]))
else:
    t = a.count(y)
    while len(a) < n//2 + 1:
        a.append(y)
    a.sort()
    a.reverse()
    while len(a) < n and a[n//2] < y:
        a.append(y)
        a.sort()
        a.reverse()
    leny = a.count(y) - t
    len1 = n - len(a)
    a += [1 for _ in range(len1)]
    print(-1 if a[n//2] < y or sum(a) > x else ' '.join([str(y) for _ in range(leny)] + ['1' for _ in range(len1)]))
    
