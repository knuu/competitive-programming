import heapq, bisect, math, collections, sys, fractions, copy, functools, operator, itertools, string

argmax = lambda l: l.index(max(l))
argmin = lambda l: l.index(min(l))

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]


def main():
    array = [1]
    w = 2
    L = 10**18
    while w <= L:
        u = 1
        while w * u <= L:
            array.append(w*u)
            u *= 3
        w <<= 1
    array.sort()

    for i in range(read_line(int)):
        l, r = read_list(int)
        lb, ub = bisect.bisect_left(array, l), bisect.bisect_right(array, r)
        print(ub-lb)

if __name__ == '__main__':
    main()
