import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import minimum_spanning_tree


def main() -> None:
    N, M = map(int, input().split())
    large, small = [], []
    for i in range(N):
        x, y, c = map(int, input().split())
        large.append((x, y, c))
    for i in range(M):
        x, y, c = map(int, input().split())
        small.append((x, y, c))

    ans = 1e9
    for state in range(1 << M):
        vertex = large[:]
        for i in range(M):
            if state >> i & 1:
                vertex.append(small[i])
        V = len(vertex)
        X = np.zeros((V, V))
        for i in range(V):
            for j in range(i+1, V):
                x1, y1, c1 = vertex[i]
                x2, y2, c2 = vertex[j]
                cost = np.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
                if c1 != c2:
                    cost *= 10
                X[i, j] = X[j, i] = cost

        X = csr_matrix(X)
        Tcsr = minimum_spanning_tree(X)
        ans = min(ans, Tcsr.sum())
    print("{:.20f}".format(ans))


if __name__ == '__main__':
    main()
