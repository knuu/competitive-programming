from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import maximum_bipartite_matching


def main() -> None:
    N = int(input())
    red, blue = [], []
    for _ in range(N):
        red.append(tuple(map(int, input().split())))
    for _ in range(N):
        blue.append(tuple(map(int, input().split())))

    graph = []
    for xr, yr in red:
        graph.append([xr <= xb and yr <= yb for xb, yb in blue])
    graph = csr_matrix(graph)
    print((maximum_bipartite_matching(graph) >= 0).sum())


if __name__ == '__main__':
    main()
