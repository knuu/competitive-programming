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

H, W = map(int, input().split())
S = [input() for _ in range(H)]
"""
setreclim(3000)
memo = [[2 for _ in range(W)] for _ in range(H)]

def dfs(i, j):
    if i == H or j == W or S[i][j] == '#':
        return True
    if memo[i][j] != 2:
        return memo[i][j]
    
    result = False
    if dfs(i+1, j+1) == False:
        result = True
    if dfs(i+1, j) == False:
        result = True
    if dfs(i, j+1) == False:
        result = True
    memo[i][j] = result
    return result
"""
dp = [[2 for _ in range(W+1)] for _ in range(H+1)]
for i in range(W+1): dp[H][i] = 1
for i in range(H+1): dp[i][W] = 1
for i in range(H-1, -1, -1):
    for j in range(W-1, -1, -1):
        if S[i][j] == '#' or dp[i+1][j] == 0 or dp[i+1][j+1] == 0 or dp[i][j+1] == 0:
            dp[i][j] = 1
        else:
            dp[i][j] = 0
print('First' if dp[0][0] else 'Second')
