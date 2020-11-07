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

H, W = map(int, input().split())
uft = UnionFindTree(H * W)
board = [input() for _ in range(H)]
drc = [(1, 0), (0, 1)]
for r in range(H):
    for c in range(W):
        if r < H - 1 and board[r + 1][c] != board[r][c]:
            uft.unite(r * W + c, (r + 1) * W + c)
        if c < W - 1 and board[r][c + 1] != board[r][c]:
            uft.unite(r * W + c, r * W + c + 1)
par_dict_w, par_dict_b = dict(), dict()
for r in range(H):
    for c in range(W):
        par = uft.find(r * W + c)
        if board[r][c] == "#":
            par_dict_b[par] = par_dict_b.get(par, 0) + 1
        else:
            par_dict_w[par] = par_dict_w.get(par, 0) + 1
print(sum(par_dict_w[k] * par_dict_b.get(k, 0) for k in par_dict_w.keys()))
