def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N = read_line(int)
A = read_list(int)

if sum(A) % N != 0:
    print(-1)
    exit(0)
else:
    s = sum(A) // N

ans = 0
i = 0
suc = 0
suc_sum = 0
while i < N:
    suc_sum += A[i]
    suc += 1
    if suc * s == suc_sum:
        suc = 0
        suc_sum = 0
    else:
        ans += 1
    i += 1
print(ans)
