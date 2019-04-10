from copy import deepcopy
import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input


class Matrix:
    ZERO = 0
    ONE = (1 << 32) - 1

    def __init__(self, mat):
        assert(len(mat) and len(mat[0]))
        self.mat = deepcopy(mat)

    def __mult__(self, other):
        ret = [[self.ZERO] * len(other.mat[0]) for _ in range(len(self.mat))]
        for i in range(len(self.mat)):
            for j in range(len(self.mat[0])):
                for k in range(len(self.mat[0])):
                    ret[i][j] ^= self.mat[i][k] & other.mat[k][j]
        return Matrix(ret)

    def __pow__(self, k):
        ret = Matrix([[self.ZERO] * len(self.mat[0]) for _ in range(len(self.mat))])
        for i in range(len(self.mat)):
            ret.mat[i][i] = self.ONE
        n = Matrix(deepcopy(self.mat))

        while k:
            if k & 1:
                ret = ret.__mult__(n)
            n = n.__mult__(n)
            k >>= 1
        return ret

    def __str__(self):
        return '[{}]\n'.format('\n'.join(str(row) for row in self.mat))

K, M = map(int, input().split())
A = [int(x) for x in input().split()]
m = [[0] * K for _ in range(K)]

m[0] = [int(x) for x in input().split()]
for i in range(K-1):
    m[i+1][i] = (1 << 32) - 1

if M <= K:
    print(A[M-1])
else:
    mat = Matrix(m) ** (M - K)
    ans = 0
    for a, b in zip(A[::-1], mat.mat[0]):
        ans ^= a & b
    print(ans)
