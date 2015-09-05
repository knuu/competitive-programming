def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

for i in range(read_line(int)):
    N = read_line(int)
    print(min(read_list(int)) * (N-1))
