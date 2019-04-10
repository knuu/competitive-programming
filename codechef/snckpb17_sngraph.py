class UnionFindTree:
    """Disjoint-Set Data Structure
       Union-Find Tree
       complexity:
          init: O(n)
          find, unite, same: O(alpha(n))
       used in SRM505 div.2 900, ATC001 A, DSL1A(AOJ)
    """
    def __init__(self, n):
        self.par = list(range(n))  # parent
        self.rank = [0] * n  # depth of tree

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)


for _ in range(int(input())):
    N, M = map(int, input().split())
    edge = [[] for _ in range(N)]
    for _ in range(M):
        x, y = map(lambda x: int(x) - 1, input().split())
        edge[x].append(y)
        edge[y].append(x)
    dim = [[] for _ in range(N)]
    vs = []
    for i in range(N):
        dim[len(edge[i])].append(i)
        vs.append((len(edge[i]), i))
    vs.sort()
    mst = [[] for _ in range(N)]
    uf = UnionFindTree(N)
    for d, v in vs:
        for e in edge[v]:
            if not uf.same(v, e):
                mst[v].append(e)
                mst[e].append(v)
                uf.unite(v, e)
    edge_set = set()
    ans = [min(N - 1, len(dim[0]))]
    for d in range(1, N):
        for v in dim[d]:
            for e in mst[v]:
                edge_set.add((min(v, e), max(v, e)))
        ans.append(min(N - 1, len(dim[0]) + len(edge_set)))
    print(*ans)
