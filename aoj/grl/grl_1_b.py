class BellmanFord:
    """Bellman-Ford algorithm : find the shortest path from a vertex
       Complexity: O(VE)
       used in GRL1A(AOJ)
    """

    def __init__(self, V, E, start, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list (all edge in E must be 0 or positive)
            start: start vertex
            INF: Infinity distance
        """
        self.V = V
        self.E = E
        self.bellman_ford(start, INF)

    def bellman_ford(self, start, INF):
        self.distance = [INF] * self.V # distance from start
        self.prev = [-1] * self.V # prev vertex of shortest path
        self.distance[start] = 0
        self.negativeCycle = False
        
        for i in range(V):
            update = False
            for v in range(V):
                for to, cost in self.E[v]:
                    if self.distance[v] != INF and self.distance[v] + cost < self.distance[to]:
                        self.distance[to] = self.distance[v] + cost
                        self.prev[to] = v
                        update = True
                        if i == V - 1:
                            self.negativeCycle = True
            if update == False:
                break

    def getPath(self, end):
        assert self.hasNegativeCycle() == False
        path = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]

    def hasNegativeCycle(self):
        return self.negativeCycle

V, E, r = map(int, input().split())
INF = 10**9
edge = [[] for _ in range(V)]
for _ in range(E):
    s, t, d = map(int, input().split())
    edge[s].append((t, d))

sp = BellmanFord(V, edge, r, INF)
if sp.hasNegativeCycle():
    print('NEGATIVE CYCLE')
else:
    print(*[dist if dist != INF else 'INF' for dist in sp.distance], sep='\n')
