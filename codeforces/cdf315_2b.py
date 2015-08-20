def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N = read_line(int)
A = read_list(int)
unused = list(set(range(1, N+1)) - set(A))
cur = 0
used = [False] * (N+1)

for i, a in enumerate(A):
    if a > N or used[a]:
        A[i] = unused[cur]
        used[A[i]] = True
        cur += 1
    else:
        used[a] = True
print(*A)
