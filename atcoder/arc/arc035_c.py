n, m = map(int, input().split())
e = [list(map(int, input().split())) for _ in range(m)]
k = int(input())
new_e = [list(map(int, input().split())) for _ in range(k)]

d = [[10**9 for i in range(n)] for _ in range(n)]

for f, t, c in e:
    d[f-1][t-1], d[t-1][f-1] = c, c

for i in range(n): d[i][i] = 0

def warshall_floyd(cost, v):
    for k in range(v):
        for i in range(v):
            for j in range(v):
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])
    return cost

d = warshall_floyd(d, n)
ans = sum([sum(d[i][i+1:]) for i in range(n)])

for x, y, z in new_e:
    x, y = x-1, y-1
    for i in range(n):
        for j in range(n):
            if i<j: ans -= d[i][j]
            d[i][j] = min(d[i][j], d[i][x] + z + d[y][j], d[i][y] + z + d[x][j])
            if i<j: ans += d[i][j]
    print(ans)
