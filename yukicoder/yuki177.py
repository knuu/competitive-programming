import collections


class MaxFlow:
    """Dinic Algorithm: find max-flow
       complexity: O(EV^2)
       used in GRL6A(AOJ)
    """
    class Edge:
        def __init__(self, to, cap, rev):
            self.to, self.cap, self.rev = to, cap, rev

    def __init__(self, V):
        """ V: the number of vertexes
            E: adjacency list
            source: start point
            sink: goal point
        """
        self.V = V
        self.E = [[] for _ in range(V)]

    def add_edge(self, fr, to, cap):
        self.E[fr].append(self.Edge(to, cap, len(self.E[to])))
        self.E[to].append(self.Edge(fr, 0, len(self.E[fr])-1))

    def dinic(self, source, sink, INF=10**9):
        """find max-flow"""
        maxflow = 0
        while True:
            self.bfs(source)
            if self.level[sink] < 0:
                return maxflow
            self.itr = [0] * self.V
            while True:
                flow = self.dfs(source, sink, INF)
                if flow > 0:
                    maxflow += flow
                else:
                    break

    def dfs(self, vertex, sink, flow):
        """find augmenting path"""
        if vertex == sink:
            return flow
        for i in range(self.itr[vertex], len(self.E[vertex])):
            self.itr[vertex] = i
            e = self.E[vertex][i]
            if e.cap > 0 and self.level[vertex] < self.level[e.to]:
                d = self.dfs(e.to, sink, min(flow, e.cap))
                if d > 0:
                    e.cap -= d
                    self.E[e.to][e.rev].cap += d
                    return d
        return 0

    def bfs(self, start):
        """find shortest path from start"""
        que = collections.deque()
        self.level = [-1] * self.V
        que.append(start)
        self.level[start] = 0

        while que:
            fr = que.popleft()
            for e in self.E[fr]:
                if e.cap > 0 and self.level[e.to] < 0:
                    self.level[e.to] = self.level[fr] + 1
                    que.append(e.to)

W = int(input())
N = int(input())
J = [int(x) for x in input().split()]
M = int(input())
C = [int(x) for x in input().split()]

mf = MaxFlow(N+M+2)
source, sink = N+M, N+M+1
INF = 10**9
for i, j in enumerate(J):
    mf.add_edge(source, i, j)
for i, c in enumerate(C):
    mf.add_edge(N+i, sink, c)
    _, *X = [int(x)-1 for x in input().split()]
    for j in range(N):
        if j not in X:
            mf.add_edge(j, i+N, INF)
maxflow = mf.dinic(source, sink)
print("SHIROBAKO" if maxflow >= W else "BANSAKUTSUKITA")
