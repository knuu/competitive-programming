import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import dijkstra

N, M, s, t = map(int, input().split())
s, t = s - 1, t - 1

yen, snuke = [], []
for _ in range(M):
    u, v, a, b = map(int, input().split())
    u, v = u - 1, v - 1
    yen.append([u, v, a])
    yen.append([v, u, a])
    snuke.append([u, v, b])
    snuke.append([v, u, b])

yen, snuke = np.asarray(yen), np.asarray(snuke)
yen_g = csr_matrix((yen[:, 2], (yen[:, 0], yen[:, 1])), shape=(N, N), dtype=np.int64)
snuke_g = csr_matrix((snuke[:, 2], (snuke[:, 0], snuke[:, 1])), shape=(N, N), dtype=np.int64)

yen_d = dijkstra(yen_g, indices=s)
snuke_d = dijkstra(snuke_g, indices=t)

pque = []
ans = []
min_cost = 10 ** 15
for i in range(N):
    min_cost = min(min_cost, int(yen_d[N-i-1] + snuke_d[N-i-1]))
    ans.append(10 ** 15 - min_cost)
for a in ans[::-1]:
    print(a)
