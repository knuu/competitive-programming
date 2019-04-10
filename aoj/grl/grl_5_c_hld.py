import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input


class HeavyLightDecomposition:
    def __init__(self, g, root=0):
        self.g = g
        self.vid, self.head, self.heavy, self.parent = [0] * len(g), [-1] * len(g), [-1] * len(g), [-1] * len(g)
        self.dfs(root)
        self.bfs(root)

    def dfs(self, root):
        stack = [(root, -1)]
        sub, max_sub = [1] * len(self.g), [(0, -1)] * len(self.g)
        used = [False] * len(self.g)
        while stack:
            v, par = stack.pop()
            if not used[v]:
                self.parent[v] = par
                used[v] = True
                stack.append((v, par))
                stack.extend((c, v) for c in self.g[v] if c != par)
            else:
                if par != -1:
                    sub[par] += sub[v]
                    if sub[v] > max_sub[par][0]:
                        max_sub[par] = max(max_sub[par], (sub[v], v))
                self.heavy[v] = max_sub[v][1]

    def bfs(self, root=0):
        from collections import deque
        k, que = 0, deque([root])
        while que:
            r = v = que.popleft()
            while v != -1:
                self.vid[v], self.head[v] = k, r
                for c in self.g[v]:
                    if c != self.parent[v] and c != self.heavy[v]:
                        que.append(c)
                k += 1
                v = self.heavy[v]

    def lca(self, u, v):
        while self.head[u] != self.head[v]:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
            v = self.parent[self.head[v]]
        else:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
        return u

N = int(input())
g = [[] for _ in range(N)]
for i in range(N):
    for c in map(int, input().split()[1:]):
        g[i].append(c)
        g[c].append(i)
hld = HeavyLightDecomposition(g)
Q = int(input())
for _ in range(Q):
    u, v = map(int, input().split())
    print(hld.lca(u, v))
