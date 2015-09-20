def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

mod = 10**9+7

N = read_line(int)
M = 0
A = read_list(int)
bucket = [0] * (max(A)+1)
for a in A:
    bucket[a] += 1
    M = max(M, a)
if bucket[0] != 1 or A[0] != 0:
    print(0)
    exit(0)

v = [pow(2, i*(i-1)//2, mod) for i in range(max(bucket)+1)]

ans = v[bucket[M]]

for i in reversed(range(1, M)):
    ans *= pow(pow(2, bucket[i], mod) - 1, bucket[i+1], mod) * v[bucket[i]]
    ans %= mod
print(ans)
