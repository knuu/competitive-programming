from collections import defaultdict


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


N, M = map(int, input().split())
uf = UnionFindTree(N)
box = [int(x) for x in input().split()]
edge = [[] for _ in range(N)]
for _ in range(M):
    x, y = [int(x) - 1 for x in input().split()]
    uf.unite(x, y)
    edge[x].append(y)
    edge[y].append(x)
for i in range(N):
    uf.find(i)

conn = defaultdict(list)
conn_edge = defaultdict(list)
for i in range(N):
    conn[uf.par[i]].append(i)
    for x in edge[i]:
        conn_edge[uf.par[i]].append((i, x))

ans = 0
for key, val in conn.items():
    V, E = len(val), len(conn_edge[key]) // 2
    points = [box[v] for v in val]
    ans += sum(points)
    if V - 1 == E:
        ans -= min(points)
print(ans)
