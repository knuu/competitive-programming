from heapq import heapify, heappush, heappop
from collections import Counter, defaultdict, deque, OrderedDict
from sys import setrecursionlimit as setreclim
from sys import maxsize
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

