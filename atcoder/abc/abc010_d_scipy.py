from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import maximum_flow


def main() -> None:
    N, _, E = map(int, input().split())
    in_, out, weight = [], [], []
    source, sink = 0, N
    for p in map(int, input().split()):
        in_.append(p)
        out.append(sink)
        weight.append(1)
    for _ in range(E):
        a, b = map(int, input().split())
        in_.append(a)
        out.append(b)
        weight.append(1)
    flow = csr_matrix((weight, (in_, out)), shape=(N+1, N+1))
    print(maximum_flow(flow, source, sink).flow_value)


if __name__ == '__main__':
    main()
