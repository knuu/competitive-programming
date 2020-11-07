import math
from scipy.optimize import newton

PI = math.acos(-1)


def main() -> None:
    A, B, C = map(int, input().split())

    def g(t):
        return A * t + B * math.sin(C * t * PI) - 100

    def dg(t):
        return A + B * math.cos(C * t * PI) * C * PI

    def d2g(t):
        return - B * math.sin(C * t * PI) * C * PI * C * PI

    # root = newton(g, x0=100/A, tol=1e-6)
    # 一階微分を使う場合
    # root = newton(g, x0=100/A, fprime=dg, tol=1e-6)
    # 二階微分を使う場合
    root = newton(g, x0=100/A, fprime=dg, fprime2=d2g, tol=1e-6)
    print(root)


if __name__ == '__main__':
    main()
