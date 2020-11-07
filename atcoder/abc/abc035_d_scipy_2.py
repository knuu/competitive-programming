import numpy as np
from scipy.sparse.csgraph import dijkstra
from scipy.sparse import csr_matrix


def main() -> None:
    N, M, T = map(int, input().split())
    A = np.array([int(x) for x in input().split()])

    # sparse 行列作成
    in_, out, weight = [], [], []
    for _ in range(M):
        s, t, w = map(int, input().split())
        in_.append(s - 1)
        out.append(t - 1)
        weight.append(w)

    graph = csr_matrix((weight, (in_, out)), shape=(N, N), dtype=np.int64)
    inv_graph = csr_matrix((weight, (out, in_)), shape=(N, N), dtype=np.int64)

    # dijkstra 法で最短経路を計算
    dists = dijkstra(graph, indices=0)
    inv_dists = dijkstra(inv_graph, indices=0)

    # 答えを計算
    print(int(np.max(A * (T - (dists + inv_dists)))))


if __name__ == '__main__':
    main()
