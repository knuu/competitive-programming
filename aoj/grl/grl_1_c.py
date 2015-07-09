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

class WarshallFloyd():
    """Warshall-Floyd Algorithm: 
       find the lengths of the shortest paths between all pairs of vertices
    """

    def __init__(self, V, E, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list
            start: start vertex
            INF: Infinity distance
        """
        self.V = V
        self.E = E
        self.warshall_floyd(INF)

    def warshall_floyd(self, INF):
        self.distance = [[INF] * self.V for _ in range(V)]
        for i in range(V): self.distance[i][i] = 0
        for fr in range(V):
            for to, cost in self.E[fr]:
                self.distance[fr][to] = cost
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if self.distance[i][k] != INF and self.distance[k][j] != INF:
                        self.distance[i][j] = min(self.distance[i][j], self.distance[i][k] + self.distance[k][j])

    def hasNegativeCycle(self):
        for i in range(V):
            if self.distance[i][i] < 0:
                return True
        else:
            return False
                
V, E = map(int, input().split())
INF = 10**10
edge = [[] for _ in range(V)]

for i in range(E):
    s, t, cost = map(int, input().split())
    edge[s].append((t, cost))

allsp = WarshallFloyd(V, edge, INF)
            
if allsp.hasNegativeCycle():
    print('NEGATIVE CYCLE')
else:
    for dist in allsp.distance:
        print(*[d if d != INF else 'INF' for d in dist])
