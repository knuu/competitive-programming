from scipy.optimize import linprog


def main() -> None:
    C, D = map(int, input().split())

    c = [-1000, -2000]
    A = [[3/4, 2/7], [1/4, 5/7]]
    b = [C, D]
    bounds = [(0, None), (0, None)]
    res = linprog(c, A_ub=A, b_ub=b, bounds=bounds, options={'tol': 1e-9})
    print(-res.fun)


if __name__ == '__main__':
    main()
