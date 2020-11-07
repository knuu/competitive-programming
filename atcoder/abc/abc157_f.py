import time
start = time.time()
import numpy as np
from scipy.optimize import basinhopping, minimize
import sys
input = sys.stdin.buffer.readline

def main() -> None:
    N, K = map(int, input().split())
    A = np.array(list(map(int, sys.stdin.read().split())))
    X, Y, C = A[::3], A[1::3], A[2::3]
    def f(x, X=X, Y=Y, C=C):
        return np.sort(C * np.sqrt(np.power(X-x[0], 2) + np.power(Y-x[1], 2)))[K-1]
    ans = 1e9
    ans_ps = []
    for i, (x, y) in enumerate(zip(X, Y)):
        res = minimize(f, [x, y], method='Nelder-Mead', tol=1e-7, options={"fatol": 1e-7})
        cand = f(res.x)
        ans = min(ans, cand)
        ans_ps.append((cand, i))
    #print(x0)
    # res = basinhopping(f, x0, niter=100)
    ans_ps.sort()
    cands = [(i, j) for i in range(N) for j in range(i+1, N)]
    cands.sort(key=lambda x: x[0] + x[1])
    print(ans_ps)
    for ii, jj in cands:
        # if time.time() - start > 1.935:
        #     break
        i, j = ans_ps[ii][1], ans_ps[jj][1]
        x0 = [(X[i] + X[j]) / 2, (Y[i] + Y[j]) / 2]
        res = minimize(f, x0, method='Nelder-Mead', tol=1e-7, options={"fatol": 1e-7})
        cand = f(res.x)
        if cand < ans:
            ans = cand
            print(ii, jj)
        # ans = min(ans, cand)
    print("{:.20f}".format(ans))


if __name__ == '__main__':
    main()
