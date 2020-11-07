import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import connected_components


def create_graph(V: int, edges: np.array, dtype=None):
    """csr_matrix を作成する

    もし精度が足りない場合は dtype=object にする。
    """
    return csr_matrix((edges[:, 2], (edges[:, 0], edges[:, 1])),
                      shape=(V, V), dtype=dtype)


def main() -> None:
    N, M = map(int, input().split())
    edges = []
    adj_list = [[] for _ in range(N)]
    for _ in range(M):
        x, y = map(int, input().split())
        edges.append([x-1, y-1, 1])
        adj_list[x-1].append(y-1)
    graph = create_graph(N, np.asarray(edges))
    _, labels = connected_components(
        csgraph=graph, directed=True,
        connection="strong", return_labels=True)
    order = [(x, i) for i, x in enumerate(labels)]
    order.sort(reverse=True)
    dp = [0] * N
    for _, i in order:
        for v in adj_list[i]:
            dp[v] = max(dp[v], dp[i] + 1)
    print(max(dp))


if __name__ == '__main__':
    main()
