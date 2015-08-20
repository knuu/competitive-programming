def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

H = read_list(int)

print((H[0] + H[1] + H[2]) ** 2 - H[0] ** 2 - H[2] ** 2 - H[4] ** 2)
