class UnionFindTree:
    """Disjoint-Set Data Structure
       Union-Find Tree
       complexity: 
          init: O(n)
          find, unite, same: O(alpha(n))
       used in SRM505 div.2 900, 
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
        x, y = self.find(x), self.find(y)
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
DisjointSet = UnionFindTree(N)
for _ in range(Q):
    com, x, y = map(int, input().split())
    if com == 0:
        DisjointSet.unite(x, y)
    elif com == 1:
        print(int(DisjointSet.same(x, y)))
