import numpy as np


def main():
    N, K = map(int, input().split())
    mod = 10 ** 9 + 7
    A = [[int(x) for x in input().split()] for _ in range(N)]
    A = np.asarray(A, dtype=object)
    ans = np.identity(N, dtype=object)
    while K > 0:
        if K & 1:
            ans = np.mod(np.dot(ans, A), mod)
        A = np.mod(np.dot(A, A), mod)
        K >>= 1
    print(ans.sum() % mod)


if __name__ == '__main__':
    main()
