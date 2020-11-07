from scipy.optimize import minimize_scalar


def main() -> None:
    P = float(input())

    def f(t, k=2/3):
        return t + P / pow(2, t * k)

    res = minimize_scalar(f, method="golden", tol=1e-8)
    print(P if res.x < 0 else res.fun)


if __name__ == '__main__':
    main()
