from math import hypot
from statistics import mean
N = int(input())
xA, yA = [0]*N, [0]*N
xB, yB = [0]*N, [0]*N
for i in range(N):
    xA[i], yA[i] = map(int, input().split())
for i in range(N):
    xB[i], yB[i] = map(int, input().split())
gxA, gyA = sum(xA)/N, sum(yA)/N
gxB, gyB = sum(xB)/N, sum(yB)/N
maxDistA, maxDistB = 0, 0
for i in range(N):
    maxDistA = max(maxDistA, hypot(xA[i]-gxA, yA[i]-gyA))
for i in range(N):
    maxDistB = max(maxDistB, hypot(xB[i]-gxB, yB[i]-gyB))
print(maxDistB/maxDistA)
