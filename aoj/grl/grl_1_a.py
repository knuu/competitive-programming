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
        heapq.heappush(que, (0, start))

        while len(que) > 0:
            cost, v = heapq.heappop(que)
            if self.dist[v] < cost:
                continue
            if goal is not None and v == goal:
                return
            for e in self.G.E[v]:
                if self.dist[v] + e.weight < self.dist[e.dst]:
                    self.dist[e.dst] = self.dist[v] + e.weight
                    heapq.heappush(que, (self.dist[e.dst], e.dst))
                    self.prev[e.dst] = v

    def getPath(self, end):
        path = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]

V, E, start = map(int, input().split())
G = Graph(V)
for _ in range(E):
    s, t, d = map(int, input().split())
    G.add_edge(s, t, d)
INF = 10**9
sp = ShortestPath(G, INF)
sp.dijkstra(start)
for i in range(G.V):
    print("INF" if sp.dist[i] == INF else sp.dist[i])
