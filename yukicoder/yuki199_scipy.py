import numpy as np
from scipy.spatial import ConvexHull
from scipy.spatial.qhull import QhullError

points = []
for _ in range(5):
    x, y = map(int, input().split())
    points.append([x, y])
points = np.asarray(points)
try:
    hull = ConvexHull(points)
except QhullError:
    print("NO")
    quit()

print("YES" if hull.nsimplex == 5 else "NO")
