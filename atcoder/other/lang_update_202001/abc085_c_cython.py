import cython


def main() -> None:
    cython.declare(N=cython.int, Y=cython.int,
                   i=cython.int, j=cython.int, k=cython.int)
    N, Y = map(int, input().split())
    for i in range(N + 1):
        for j in range(N - i + 1):
            k = N - i - j
            if 10000 * i + 5000 * j + 1000 * k == Y:
                print(i, j, k)
                return
    print(-1, -1, -1)


if __name__ == '__main__':
    main()
