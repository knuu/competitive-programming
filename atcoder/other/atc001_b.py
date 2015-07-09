class UnionFindTree:
    """Disjoint-Set Data Structure
       Union-Find Tree
       complexity: 
          init: O(n)
          find, unite, same: O(alpha(n))
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

N, Q = map(int, input().split())
uf = UnionFindTree(N)
for _ in range(Q):
    p, a, b = map(int, input().split())
    if p == 0:
        uf.unite(a, b)
    else:
        print('Yes' if uf.same(a, b) else 'No')
