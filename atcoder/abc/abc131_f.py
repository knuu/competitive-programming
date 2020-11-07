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


N = int(input())
M = 10 ** 5
uft = UnionFindTree(2 * M)

for _ in range(N):
    x, y = map(int, input().split())
    x, y = x-1, y-1
    uft.unite(x, y + M)
x_dict, y_dict = dict(), dict()
for x in range(M):
    par_x = uft.find(x)
    x_dict[par_x] = x_dict.get(par_x, 0) + 1
for y in range(M, 2 * M):
    par_y = uft.find(y)
    y_dict[par_y] = y_dict.get(par_y, 0) + 1
ans = -N
for r in x_dict.keys():
    ans += x_dict.get(r, 0) * y_dict.get(r, 0)
print(ans)
