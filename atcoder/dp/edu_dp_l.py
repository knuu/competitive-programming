import sys
sys.setrecursionlimit(2 * 10**5)


def rec(left, right, A, memo):
    if left + right == len(A):
        return 0
    if memo[left][right] is not None:
        return memo[left][right]
    if (left + right) % 2 == 0:
        ret = max(rec(left + 1, right, A, memo) + A[left],
                  rec(left, right + 1, A, memo) + A[len(A)-1-right])
    else:
        ret = min(rec(left + 1, right, A, memo) - A[left],
                  rec(left, right + 1, A, memo) - A[len(A)-1-right])
    memo[left][right] = ret
    return ret


def main():
    N = int(input())
    A = [int(x) for x in input().split()]
    memo = [[None] * N for _ in range(N)]
    print(rec(0, 0, A, memo))


if __name__ == '__main__':
    main()
