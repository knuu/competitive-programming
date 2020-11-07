import numpy as np
from scipy.optimize import minimize_scalar


def main() -> None:
    N = int(input())
    X, Y, C = [], [], []
    for _ in range(N):
        x, y, c = map(int, input().split())
        X.append(x)
        Y.append(y)
        C.append(c)
    X, Y, C = np.asarray(X), np.asarray(Y), np.asarray(C)

    def f(x, X=X, C=C):
        return (np.abs(X-x)*C).max()

    def g(y, Y=Y, C=C):
        return (np.abs(Y-y)*C).max()

    x_min = minimize_scalar(f, method="golden", tol=1e-4).x
    y_min = minimize_scalar(g, method="golden", tol=1e-4).x
    print((np.max([np.abs(X-x_min), np.abs(Y-y_min)], axis=0) * C).max())


if __name__ == '__main__':
    main()
