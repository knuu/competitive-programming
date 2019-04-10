from math import hypot
a, b = map(int, input().split())
n = int(input())
ans = 10**6
for _ in range(n):
    x, y, v = map(int, input().split())
    ans = min(ans, hypot(x-a, y-b)/v)
print('{:.20f}'.format(ans))
