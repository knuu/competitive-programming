import sys
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import floyd_warshall
import numpy as np

N, M, L = map(int, sys.stdin.buffer.readline().split())
rest = np.array(sys.stdin.buffer.read().split(), np.int)
in_, out, weight = rest[0:3*M:3], rest[1:3*M:3], rest[2:3*M:3]

graph = csr_matrix((weight, (in_, out)), shape=(N+1, N+1))
graph = floyd_warshall(graph, directed=False)
graph = floyd_warshall(graph <= L, directed=False)
graph[np.isinf(graph)] = 0

S, T = rest[3*M+1::2], rest[3*M+2::2]
print('\n'.join(map(str, graph[S, T].astype(int) - 1)))
