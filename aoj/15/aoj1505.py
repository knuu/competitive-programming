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
        return path[::-1]

import bisect

class RangeTreeNode:
    def __init__(self, inf = 10**10):
        self._inf = inf
        self.range_ = (inf, inf)
        self.indices = []
        self.assoc = []

    @classmethod
    def merge(cls, node1, node2, data):
        merged_node = cls()
        merged_node.range_ = (min(node1.range_[0], node2.range_[0]),
                              max(node1.range_[1], node2.range_[1]))
        sentinel = node1._inf
        node1.assoc.append(sentinel)
        node2.assoc.append(sentinel)
        i = j = 0
        while min(node1.assoc[i], node2.assoc[j]) < sentinel:
            if node1.assoc[i] < node2.assoc[j] or \
               (node1.assoc[i] == node2.assoc[j] and \
                data[node1.indices[i]][0] < data[node2.indices[j]][0]):
                merged_node.assoc.append(node1.assoc[i])
                merged_node.indices.append(node1.indices[i])
                i += 1
            else:
                merged_node.assoc.append(node2.assoc[j])
                merged_node.indices.append(node2.indices[j])
                j += 1
        node1.assoc.pop()
        node2.assoc.pop()
        return merged_node

class RangeTree2D:
    def __init__(self, inf = 10**10):
        self._inf = inf

    def build(self, points):
        points = sorted([(x, y, i) for i, (x, y) in enumerate(points)])
        self._size = 1
        while self._size < len(points):
            self._size <<= 1
        self._data = [RangeTreeNode() for _ in range(self._size * 2 - 1)]
        for i, (x, y, idx) in enumerate(points):
            self._data[self._size - 1 + i].range_ = (x, x)
            self._data[self._size - 1 + i].indices.append(idx)
            self._data[self._size - 1 + i].assoc.append(y)
        for i in reversed(range(self._size - 1)):
            self._data[i] = RangeTreeNode.merge(self._data[2 * i + 1], self._data[2 * i + 2], points)

    def query(self, range_x, range_y, output, idx=0):
        if idx >= 2 * self._size - 1:
            return
        elif range_x[0] <= self._data[idx].range_[0] and self._data[idx].range_[1] <= range_x[1]:
            low = bisect.bisect_left(self._data[idx].assoc, range_y[0])
            high = bisect.bisect_left(self._data[idx].assoc, range_y[1] + 1)

            for i in range(low, high):
                output.append(self._data[idx].indices[i])
            return
        else:
            self.query(range_x, range_y, output, 2 * idx + 1)
            self.query(range_x, range_y, output, 2 * idx + 2)


if __name__ == '__main__':
    N, M = map(int, input().split())
    g = Graph(N)
    for _ in range(M):
        a, b, c = map(int, input().split())
        g.add_edge(a, b, c)
        g.add_edge(b, a, c)
    sp1, sp2 = ShortestPath(g), ShortestPath(g)
    sp1.dijkstra(0)
    sp2.dijkstra(N - 1)
