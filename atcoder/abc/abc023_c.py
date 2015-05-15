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

R, C, K = map(int, input().split())
N = int(input())
row, column = [0]*R, [0]*C

candy = []
for i in range(N):
    r, c = map(lambda x:int(x)-1, input().split())
    candy.append((r, c))
    row[r] += 1
    column[c] += 1
ans  = 0
column_sum = [0] * (N+1)
for c in column:
    column_sum[c] += 1
for r in row:
    if K - r >= 0:
        ans += column_sum[K-r]
for r, c in candy:
    if row[r] + column[c] == K:
        ans -= 1
    elif row[r] + column[c] == K+1:
        ans += 1
print(ans)
    
        
    
