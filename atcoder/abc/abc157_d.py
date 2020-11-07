class UnionFindTree:
    """Disjoint-Set Data Structure

    Union-Find Tree

    complexity:
        - init: O(n)
        - find, unite, same: O(alpha(n))
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

    def is_same(self, x, y):
        return self.find(x) == self.find(y)


def main() -> None:
    N, M, K = map(int, input().split())
    uft = UnionFindTree(N)
    ans = [-1] * N
    for i in range(M):
        a, b = map(int, input().split())
        uft.unite(a-1, b-1)
        ans[a-1] -= 1
        ans[b-1] -= 1
    groups = {}
    for i in range(N):
        p = uft.find(i)
        groups[p] = groups.get(p, 0) + 1
    for i in range(N):
        ans[i] += groups[uft.find(i)]
    for i in range(K):
        c, d = map(int, input().split())
        if uft.is_same(c-1, d-1):
            ans[c-1] -= 1
            ans[d-1] -= 1
    print(*ans)





if __name__ == '__main__':
    main()
