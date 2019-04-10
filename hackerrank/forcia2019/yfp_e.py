import math
import heapq


class Edge:
    def __init__(self, dst, weight):
        self.dst, self.weight = dst, weight

    def __lt__(self, e):
        return self.weight > e.weight


class Graph:
    def __init__(self, V):
        self.V = V
        self.E = [[] for _ in range(V)]

    def add_edge(self, src, dst, weight):
        self.E[src].append(Edge(dst, weight))


class ShortestPath:
    """Dijkstra's algorithm : find the shortest path from a vertex
       Complexity: O(E + log(V))
       used in GRL1A(AOJ)
    """

    def __init__(self, G, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list (all edge in E must be 0 or positive)
            start: start vertex
            INF: Infinity distance
        """
        self.G, self.INF = G, INF

    class Node:
        def __init__(self, v, cost):
            self.v, self.cost = v, cost

        def __lt__(self, n):
            return self.cost < n.cost

    def dijkstra(self, start, goal=None):
        que = list()
        self.dist = [self.INF] * self.G.V  # distance from start
        self.prev = [-1] * self.G.V  # prev vertex of shortest path
        self.dist[start] = 0
        heapq.heappush(que, self.Node(start, 0))

        while len(que) > 0:
            n = heapq.heappop(que)
            if self.dist[n.v] < n.cost:
                continue
            if goal is not None and n.v == goal:
                return
            for e in self.G.E[n.v]:
                if self.dist[n.v] + e.weight < self.dist[e.dst]:
                    self.dist[e.dst] = self.dist[n.v] + e.weight
                    heapq.heappush(que, self.Node(e.dst, self.dist[e.dst]))
                    self.prev[e.dst] = n.v

    def getPath(self, end):
        path = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
            path.append(end)
        return path[::-1]


N, D = map(int, input().split())
points = []
for i in range(N):
    x, y = map(int, input().split())
    points.append((x, y))
g = Graph(N)
for i in range(N):
    for j in range(i + 1, N):
        dist = math.hypot(points[i][0] - points[j][0], points[i][1] - points[j][1])
        #print(points[i], points[j], dist, dist <= D)
        if dist <= D:
            g.add_edge(i, j, 1)
            g.add_edge(j, i, 1)
sp = ShortestPath(g)
sp.dijkstra(0)
for i in sp.getPath(N - 1):
    print(i + 1)
