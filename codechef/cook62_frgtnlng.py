import heapq, bisect, math, collections, sys, fractions, copy, functools, operator, itertools, string

argmax = lambda l: l.index(max(l))
argmin = lambda l: l.index(min(l))

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

def main():
    T = read_line(int)
    for _ in range(T):
        N, K = read_list(int)
        old = read_list(str)
        now = set()
        for _ in range(K):
            now |= set(read_list(str)[1:])
        print(*map(lambda x: 'YES' if x in now else 'NO', old))

if __name__ == '__main__':
    main()
