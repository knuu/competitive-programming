import heapq, bisect, math, collections, sys, fractions, copy, functools, operator, itertools, string

argmax = lambda l: l.index(max(l))
argmin = lambda l: l.index(min(l))

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]


def main():
    s = read_line(str)
    print(s.replace('2014', '2015'))


if __name__ == '__main__':
    main()
