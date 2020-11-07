import numpy as np
from scipy.spatial import ConvexHull
from scipy.spatial.qhull import QhullError
from numpy.linalg import norm


def main():
    N = int(input())
    points = []
    for _ in range(N):
        x, y = map(int, input().split())
        points.append([x, y])

    ans = np.zeros(N)
    try:
        hull = ConvexHull(points)
    except QhullError:
        ans[points.index(min(points))] = ans[points.index(max(points))] = 0.5
        print(*ans, sep='\n')
        return

    v = hull.vertices
    diff_prev = hull.points[np.roll(v, -1)] - hull.points[v]
    diff_next = hull.points[np.roll(v, 1)] - hull.points[v]
    deg = np.arccos(np.einsum("ij, ij->i", diff_prev, diff_next) /
                    norm(diff_prev, axis=1) / norm(diff_next, axis=1))
    ans[v] = (np.pi - deg) / (2 * np.pi)
    print(*ans, sep='\n')


if __name__ == '__main__':
    main()
