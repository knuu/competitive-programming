import numpy as np
from scipy.optimize import linear_sum_assignment


def main() -> None:
    N, M = map(int, input().split())
    kights = []
    for _ in range(N):
        _, *p = input().split()
        x, y = map(int, p)
        kights.append((x, y))
    mages = []
    for _ in range(M):
        _, *p = input().split()
        m, x, y = map(int, p)
        mages.append((m, x, y))
    mages.sort(reverse=True)
    mages = mages[:N]

    mat = []
    for _, mx, my in mages:
        mat.append([abs(kx - mx) + abs(ky - my) for kx, ky in kights])
    mat = np.asarray(mat)
    row_ind, col_ind = linear_sum_assignment(mat)
    print(mat)
    print(row_ind)
    print(col_ind)
    print(mat[row_ind, col_ind].sum())


if __name__ == '__main__':
    main()
