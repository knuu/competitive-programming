import heapq, bisect, math, collections, sys, fractions, copy, functools, operator, itertools, string

argmax = lambda l: l.index(max(l))
argmin = lambda l: l.index(min(l))

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]


def main():
    N = read_line(int)
    a = read_list(int)

    print(sum(x*(2**i) for i, x in enumerate(reversed(a))))


if __name__ == '__main__':
    main()
