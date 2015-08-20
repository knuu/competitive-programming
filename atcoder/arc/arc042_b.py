import math, itertools
def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

x, y = read_list(int)
N = read_line(int)
points = [(lambda x: (int(x[0]), int(x[1])))(input().split()) for _ in range(N)]

def s(x1, y1, x2, y2, x3, y3):
    v1 = (x2 - x1, y2 - y1)
    v2 = (x3 - x1, y3 - y1)
    return abs(v1[0] * v2[1] - v1[1] * v2[0])

ans = float('inf')
for i in range(N):
    p1, p2 = points[i%N], points[(i+1)%N]
#    print(s(x, y, p1[0], p1[1], p2[0], p2[1]), math.hypot(p1[0]-p2[0], p1[1]-p2[1]))
    ans = min(ans, s(x, y, p1[0], p1[1], p2[0], p2[1]) / math.hypot(p1[0]-p2[0], p1[1]-p2[1]))
print(ans)
