import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import dijkstra

H, W = map(int, input().split())
board = [[int(x) for x in input().split()] for _ in range(H)]

drc = [(-1, 0), (0, -1), (1, 0), (0, 1)]
edges = []
for r in range(H):
    for c in range(W):
        for dr, dc in drc:
            nr, nc = r + dr, c + dc
            if 0 <= nr < H and 0 <= nc < W:
                edges.append([r * W + c, nr * W + nc, board[nr][nc]])
edges = np.asarray(edges)
graph = csr_matrix((edges[:, 2], (edges[:, 0], edges[:, 1])), shape=(H*W, H*W), dtype=np.int64)

ru, lb, rb = W-1, (H-1) * W, (H-1)*W + (W-1)
sp_lb = dijkstra(graph, indices=lb)
sp_rb = dijkstra(graph, indices=rb)
sp_ru = dijkstra(graph, indices=ru)

ans = np.inf
for r in range(H):
    for c in range(W):
        ans = min(ans, sp_lb[r*W+c] + sp_rb[r*W+c] + sp_ru[r*W+c] - 2 * board[r][c])
print(int(ans))
