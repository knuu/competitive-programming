from scipy.optimize import linprog


def main() -> None:
    R, B = map(int, input().split())
    x, y = map(int, input().split())

    c = [-1, -1]
    A = [[x, 1], [1, y]]
    b = [R, B]
    bounds = [(0, None), (0, None)]
    res = linprog(c, A_ub=A, b_ub=b, bounds=bounds, options={'tol': 1e-9})

    p1, p2 = map(int, res.x)
    ans = 0
    for i in range(-10, 10):
        for j in range(-10, 10):
            q1, q2 = p1 + i, p2 + j
            if q1 < 0 or q2 < 0 or x * q1 + q2 > R or q1 + y * q2 > B:
                continue
            ans = max(ans, q1 + q2)
    print(ans)


if __name__ == '__main__':
    main()
