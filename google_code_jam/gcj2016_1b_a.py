import numpy as np
from collections import Counter

for t in range(int(input())):
    S = input()
    cnt = Counter(S)
    A = np.array([[4, 3, 3, 5, 4, 4, 3, 5, 5, 4],  # len
                  [1, 1, 0, 2, 0, 1, 0, 2, 1, 1],  # E
                  [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],  # F
                  [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],  # G
                  [0, 0, 0, 1, 0, 0, 0, 0, 1, 0],  # H
                  [0, 0, 0, 0, 0, 1, 1, 0, 1, 1],  # I
                  [0, 1, 0, 0, 0, 0, 0, 1, 0, 2],  # N
                  [1, 1, 1, 0, 1, 0, 0, 0, 0, 0],  # O
                  [1, 0, 0, 1, 1, 0, 0, 0, 0, 0],  # R
                  [0, 0, 0, 0, 0, 0, 1, 1, 0, 0],  # S
                  [0, 0, 1, 1, 0, 0, 0, 0, 1, 0],  # T
                  [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],  # U
                  [0, 0, 0, 0, 0, 1, 0, 1, 0, 0],  # V
                  [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],  # W
                  [0, 0, 0, 0, 0, 0, 1, 0, 0, 0],  # X
                  [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]])  # Z
    b = np.array([len(S)] + [cnt[x] for x in 'EFGHINORSTUVWXZ'])
    x = np.linalg.lstsq(A, b)[0]

    eps = 1e-9
    print("Case #{}: {}".format(t+1, ''.join(str(i) * abs(xi + eps) for i, xi in enumerate(x))))
