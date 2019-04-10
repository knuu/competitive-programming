from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import dijkstra
from numpy import array, inf
N, M, T = map(int, input().split())
A = map(int, input().split())
E = array([list(map(int, input().split())) for _ in range(M)])
fr, to, w = E[:, 0]-1, E[:, 1]-1, E[:, 2]
g, rg = csr_matrix((w, (fr, to)), shape=(N, N)), csr_matrix((w, (to, fr)), shape=(N, N))
d, rd = dijkstra(g, indices=0), dijkstra(rg, indices=0)
print(max(a * (T - int(d[i] + rd[i])) for i, a in zip(range(N), A) if max(d[i], rd[i]) < inf))
