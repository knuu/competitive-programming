import collections
import sys
if sys.version[0] == '2':
    input, range = raw_input, xrange


class MyList(list):
    def __init__(self, x=[]):
        list.__init__(self, x)

    def __iadd__(self, A):
        return MyList([a + b for a, b in zip(self, A)])

    def __isub__(self, A):
        return MyList([a - b for a, b in zip(self, A)])

    def __gt__(self, A):
        for a, b in zip(self, A):
            if a != b:
                return a > b
        return False


class MaxFlow:
    """Dinic Algorithm: find max-flow
       complexity: O(EV^2)
       used in GRL6A(AOJ)
    """
    class Edge:
        def __init__(self, to, cap, rev):
            self.to, self.cap, self.rev = to, cap, rev

    def __init__(self, V, D):
        """ V: the number of vertexes
            E: adjacency list
            source: start point
            sink: goal point
        """
        self.V = V
        self.E = [[] for _ in range(V)]
        self.D = D

    def zero(self):
        return MyList([0] * self.D)

    def add_edge(self, fr, to, cap):
        self.E[fr].append(self.Edge(to, cap, len(self.E[to])))
        self.E[to].append(self.Edge(fr, self.zero(), len(self.E[fr])-1))

    def dinic(self, source, sink):
        """find max-flow"""
        INF = MyList([10**9] * self.D)
        maxflow = self.zero()
        while True:
            self.bfs(source)
            if self.level[sink] < 0:
                return maxflow
            self.itr = MyList([0] * self.V)
            while True:
                flow = self.dfs(source, sink, INF)
                if flow > self.zero():
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
            if e.cap > self.zero() and self.level[vertex] < self.level[e.to]:
                if flow > e.cap:
                    d = self.dfs(e.to, sink, e.cap)
                else:
                    d = self.dfs(e.to, sink, flow)
                if d > self.zero():
                    e.cap -= d
                    self.E[e.to][e.rev].cap += d
                    return d
        return self.zero()

    def bfs(self, start):
        """find shortest path from start"""
        que = collections.deque()
        self.level = [-1] * self.V
        que.append(start)
        self.level[start] = 0

        while que:
            fr = que.popleft()
            for e in self.E[fr]:
                if e.cap > self.zero() and self.level[e.to] < 0:
                    self.level[e.to] = self.level[fr] + 1
                    que.append(e.to)


def to_poly(a, l):
    if l == 0:
        return str(a)
    elif l == 1:
        return "{}x".format('' if a == 1 else a)
    else:
        return "{}x^{}".format('' if a == 1 else a, l)

while True:
    N, M = map(int, input().split())
    if N == M == 0:
        break
    mf = MaxFlow(N, 51)
    for _ in range(M):
        u, v, p = input().split()
        u, v = int(u)-1, int(v)-1
        poly = MyList([0] * 51)
        for x in p.split('+'):
            try:
                num = int(x)
                poly[-1] = num
            except ValueError:
                a, l = x.split('x')
                if l:
                    poly[-int(l.strip("^"))-1] = int(a) if a else 1
                else:
                    poly[-2] = int(a) if a else 1
        mf.add_edge(u, v, poly)
        mf.add_edge(v, u, poly)
    maxflow = mf.dinic(0, N-1)
    ans = '+'.join(to_poly(a, l) for a, l in zip(maxflow, reversed(range(51))) if a)
    print(ans if ans else 0)
