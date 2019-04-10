import numpy as np
import sys

if sys.version[0] == 2:
    range, input = xrange, raw_input

for t in range(int(input())):
    N, M = map(int, input().split())
    if 2**(N-2) < M:
        print("Case #{}: IMPOSSIBLE".format(t+1))
        continue
    A = [[0] * N for _ in range(N)]
    for i in range(M.bit_length()):
        for j in range(i+1):
            A[j][i+1] = 1
    A[0][N-1] = 1
    for i, s in enumerate(format(M, 'b')[::-1]):
        A[i+1][N-1] = 1 if s == '1' else 0
    print("Case #{}: POSSIBLE".format(t+1))
    for row in A:
        print(''.join(map(str, row)))
