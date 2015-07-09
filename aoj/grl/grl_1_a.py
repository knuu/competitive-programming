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

class Dijkstra:
    """Dijkstra's algorithm : find the shortest path from a vertex
       used in GRL1A(AOJ)
    """

    def __init__(self, V, E, start, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list
            start: start vertex
            INF: Infinity distance
        """
        self.V = V
        self.E = E
        self.dijkstra(start, INF)

    def dijkstra(self, start, INF):
        que = list()
        self.distance = [INF] * self.V # distance from start
        self.prev = [-1] * self.V # prev vertex of shortest path
        self.distance[start] = 0
        heappush(que, (0, start))

        while len(que) > 0:
            dist, v = heappop(que)
            if self.distance[v] < dist: continue
            for to, cost in self.E[v]:
                if self.distance[v] + cost < self.distance[to]:
                    self.distance[to] = self.distance[v] + cost
                    heappush(que, (self.distance[to], to))
                    self.prev[to] = v

    def getPath(self, end):
        path = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]

V, E, r = map(int, input().split())
INF = 10**10
edge = [[] for _ in range(V)]
for i in range(E):
    s, t, cost = map(int, input().split())
    edge[s].append((t, cost))
sp = Dijkstra(V, edge, r, INF)
print(*[dist if dist != INF else 'INF' for dist in sp.distance], sep='\n')
