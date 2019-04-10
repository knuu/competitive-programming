import numpy as np
import sys

if sys.version[0] == 2:
    range, input = xrange, raw_input

for t in range(int(input())):
    B, M = map(int, input().split())
    all_state = 2**(B*(B-1)//2)
    for state in range(all_state):
        A, AA = np.array([[0] * B for _ in range(B)]), np.array([[0] * B for _ in range(B)])
        for bit, (r, c) in enumerate(sum([[(i, j) for j in range(i+1, B)] for i in range(B)], [])):
            if state >> bit & 1:
                A[r][c], AA[r][c] = 1, 1
        ans = AA[0][B-1]
        for _ in range(B-2):
            AA = AA.dot(A)
            ans += AA[0][B-1]
        if ans == M:
            print("Case #{}: POSSIBLE".format(t+1))
            for row in A:
                print(''.join(map(str, row)))
            break
    else:
        print("Case #{}: IMPOSSIBLE".format(t+1))
