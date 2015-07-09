class WarshallFloyd():
    """Warshall-Floyd Algorithm: 
       find the lengths of the shortest paths between all pairs of vertices
       used in GRL1C(AOJ), aoj0189
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
        self.distance = [[INF] * self.V for _ in range(self.V)]
        for i in range(self.V): self.distance[i][i] = 0
        for fr in range(self.V):
            for to, cost in self.E[fr]:
                self.distance[fr][to] = cost
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if self.distance[i][k] != INF and self.distance[k][j] != INF:
                        self.distance[i][j] = min(self.distance[i][j], self.distance[i][k] + self.distance[k][j])

    def hasNegativeCycle(self):
        for i in range(self.V):
            if self.distance[i][i] < 0:
                return True
        else:
            return False
                
while True:
    E = int(input())
    if E == 0: break
    V = 0
    edge = [[] for _ in range(10)]
    for _ in range(E):
        s, t, cost = map(int, input().split())
        V = max(s, t, V)
        edge[s].append((t, cost))
        edge[t].append((s, cost))
    allsp = WarshallFloyd(V+1, edge)
    ans = (10**9, 10**9)
    for i in range(V+1):
        ans = min(ans, (sum(allsp.distance[i]), i))
    print(*ans[::-1])
