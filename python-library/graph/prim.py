class Prim:
    """ Prim's algorithm: find minimum spanning tree
        Complexity: O(E log(V))
        used in GRL2A(AOJ)
    """

    def __init__(self, V, E, start=0, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list (undirected graph)
            start: start vertex
            INF: Infinity cost
        """
        self.prim(V, E, start, INF)

    def prim(self, V, E, start=0, INF=10**9):
        used = [False] * V
        self.mincost = 0
        que = []
        heappush(que, (0, 0))
        while len(que) > 0:
            cost, v = heappop(que)
            if used[v]: continue
            used[v] = True
            ans += cost
            for to, c in E[v]:
                heappush(que, (c, to))

    def minCost(self):
        return mincost
    
