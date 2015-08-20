def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

A = read_list(int)
s = set(A)
if len(s) == 1:
    print(A[0])
else:
    for si in s:
        if A.count(si) == 1:
            print(si)
