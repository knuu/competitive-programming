import numpy as np
from scipy.sparse.csgraph import floyd_warshall


def main():
    N, M, L = map(int, input().split())
    graph = [[0] * N for _ in range(N)]
    for _ in range(M):
        s, t, w = map(int, input().split())
        if w <= L:
            graph[s-1][t-1] = graph[t-1][s-1] = w
    graph = floyd_warshall(graph, directed=False)
    graph = floyd_warshall(graph <= L, directed=False)
    graph[np.isinf(graph)] = 0

    Q = int(input())
    ans = []
    for _ in range(Q):
        s, t = map(int, input().split())
        ans.append(int(graph[s-1][t-1]) - 1)
    print(*ans, sep='\n')


if __name__ == '__main__':
    main()
