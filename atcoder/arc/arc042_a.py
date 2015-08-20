def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N, M = read_list(int)
used = [True] * N
A = read_lines(int, M)
for a in reversed(A):
    if used[a-1]:
        print(a)
        used[a-1] = False

for i, f in enumerate(used):
    if f: print(i+1)
