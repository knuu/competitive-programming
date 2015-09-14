import heapq


class Dijkstra:
    """Dijkstra's algorithm : find the shortest path from a vertex
       Complexity: O(E + log(V))
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
        self.dijkstra(start, INF)

    def dijkstra(self, start, INF):
        que = list()
        self.distance = [INF] * self.V  # distance from start
        self.prev = [-1] * self.V  # prev vertex of shortest path
        self.distance[start] = 0
        heapq.heappush(que, (0, start))

        while len(que) > 0:
            dist, fr = heapq.heappop(que)
            if self.distance[fr] < dist:
                continue
            for to, cost in self.E[fr]:
                if self.distance[fr] + cost < self.distance[to]:
                    self.distance[to] = self.distance[fr] + cost
                    heapq.heappush(que, (self.distance[to], to))
                    self.prev[to] = fr

    def getPath(self, end):
        path = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]
