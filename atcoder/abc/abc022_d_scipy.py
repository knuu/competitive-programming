import numpy as np
from scipy.spatial import ConvexHull
from scipy.spatial.qhull import QhullError


def convex_hull_around(points):
    try:
        hull = ConvexHull(points)
    except QhullError:
        min_x, min_y = points.min(axis=0)
        max_x, max_y = points.max(axis=0)
        return np.hypot(max_x-min_x, max_y-min_y)

    idx, nxt_idx = hull.vertices, np.roll(hull.vertices, 1)
    return np.linalg.norm(points[idx]-points[nxt_idx], axis=1).sum()


def main():
    N = int(input())
    pts1 = np.asarray([[int(x) for x in input().split()] for _ in range(N)])
    pts2 = np.asarray([[int(x) for x in input().split()] for _ in range(N)])

    print(convex_hull_around(pts2) / convex_hull_around(pts1))


if __name__ == '__main__':
    main()
