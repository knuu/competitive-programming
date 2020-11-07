import sys


if sys.version[0] == '2':
    input, range = raw_input, xrange
    from fractions import gcd
else:
    from math import gcd
    input = sys.stdin.readline


def main():
    N, Q = map(int, input().split())
    A = [int(x) for x in input().split()]
    S = [int(x) for x in input().split()]
    cum_gcd = [A[0]]
    for a in A[1:]:
        cum_gcd.append(gcd(cum_gcd[-1], a))
    ans = []
    for s in S:
        left, right = -1, N - 1
        while left + 1 < right:
            mid = (left + right) // 2
            if gcd(cum_gcd[mid], s) > 1:
                left = mid
            else:
                right = mid
        g = gcd(cum_gcd[right], s)
        if g == 1:
            ans.append(right + 1)
        else:
            ans.append(g)
    print(*ans, sep="\n")


if __name__ == '__main__':
    main()
