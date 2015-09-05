def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N, M = read_list(int)
small, large = M - 1, N - M
if N == 1:
    print(1)
elif small >= large:
    print(M-1)
else:
    print(M+1)
