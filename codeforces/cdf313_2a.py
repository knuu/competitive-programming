def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N = read_line(int)
print(-1 if 1 in read_list(int) else 1)
