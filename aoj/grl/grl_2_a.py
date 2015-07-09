class UnionFindTree:
    """Disjoint-Set Data Structure
       Union-Find Tree
       
       used in SRM505 div.2 900
    """
    def __init__(self, n):
        self.par = list(range(n)) # parent
        self.rank = [0] * n # depth of tree

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y: return

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)

class Kruskal:
    """ Kruskal's algorithm: find minimum spanning tree
        Complexity: O(E log(V))
        used in GRL2A(AOJ)
    """

    def __init__(self, V, E, start=0, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list (undirected graph)
        """
        self.kruskal(V, E)

    def kruskal(self, V, E):
        edges = []
        for v1 in range(V):
            for v2, cost in E[v1]:
                if v1 < v2: edges.append((cost, v1, v2))
        edges.sort(reverse=True)
        self.mincost = 0
        self.minSpanningTree = []
        uf = UnionFindTree(V)
        while len(self.minSpanningTree) < V - 1:
            cost, v1, v2 = edges.pop()
            if uf.same(v1, v2) == False:
                self.mincost += cost
                uf.unite(v1, v2)
                self.minSpanningTree.append((v1, v2, cost))

    def minCost(self):
        return self.mincost

    def getMinSpanningTree(self):
        return sorted(self.minSpanningTree)
    
V, E = map(int, input().split())
edge = [[] for _ in range(V)]
for _ in range(E):
    s, t, w = map(int, input().split())
    edge[s].append((t, w))
    edge[t].append((s, w))

msp = Kruskal(V, edge)
print(msp.minCost())
