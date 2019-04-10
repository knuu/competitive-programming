import sys
from math import sqrt


def givens(A, b):
    """ solve linear equation
        cf. http://www.slideshare.net/tmaehara/ss-18244588
        complexity: O(n^3)
        verify: kupc2012_C
    """
    def mkrot(x, y):
        r = pow(x**2+y**2, 0.5)
        return x/r, y/r

    def rot(x, y, c, s):
        return c*x+s*y, -s*x+c*y

    n = len(b)
    for i in range(n):
        for j in range(i+1, n):
            c, s = mkrot(A[i][i], A[j][i])
            b[i], b[j] = rot(b[i], b[j], c, s)
            for k in range(i, n):
                A[i][k], A[j][k] = rot(A[i][k], A[j][k], c, s)
    for i in reversed(range(n)):
        for j in range(i+1, n):
            b[i] -= A[i][j] * b[j]
        b[i] /= A[i][i]
    return b


t = [0., 1., 2.]
A = [[-(t[0]**2)/2, t[0]/sqrt(2), 1.],
     [-(t[1]**2)/2, t[1]/sqrt(2), 1.],
     [-(t[2]**2)/2, t[2]/sqrt(2), 1.]]

b = []
print('? {:.12f}'.format(t[0]))
sys.stdout.flush()
b.append(float(input()))
print('? {:.12f}'.format(t[1]))
sys.stdout.flush()
b.append(float(input()))
print('? {:.12f}'.format(t[2]))
sys.stdout.flush()
b.append(float(input()))

g, v, h = givens(A, b)
print('! {:.12f} {:.12f} {:.12f}'.format(h, v, g))
sys.stdout.flush()
