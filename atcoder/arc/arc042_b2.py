def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

p = complex(*read_list(int))
N = read_line(int)
points = [complex(*read_list(int)) for _ in range(N)]

ans = float('inf')
for i in range(N):
    p1, p2 = points[i%N], points[(i+1)%N]
    ans = min(ans, ((p-p1) / (p2-p1) * abs(p2-p1)).imag)
print(ans)
