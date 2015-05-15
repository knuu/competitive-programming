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

N = int(input())
S = input()
cnt = 0
nec = 'b'
while len(nec) < N:
    if (cnt+1) % 3 == 1:
        nec = 'a' + nec + 'c'
    elif (cnt+1) % 3 == 2:
        nec = 'c' + nec + 'a'
    else:
        nec = 'b' + nec + 'b'
    cnt += 1
if nec == S:
    print(cnt)
else:
    print(-1)
