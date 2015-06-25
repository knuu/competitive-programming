from sys import setrecursionlimit as setrec
setrec(10010)

def dfs(i, s, cnt):
    if colored[i][s] > 0: return
    colored[i][s] = cnt
    for t in g[i][s]:
        dfs(i, t, cnt)

ver_n, edge_n = map(int, input().split())
g = [[[] for _ in range(ver_n)] for _ in range(edge_n)]
for _ in range(edge_n):
    a, b, c = map(lambda x: int(x)-1, input().split())
    g[c][a].append(b)
    g[c][b].append(a)

colored = [[0] * ver_n for _ in range(edge_n)]
for i in range(edge_n):
    cnt = 1
    for j in range(ver_n):
        dfs(i, j, cnt)
        cnt += 1

q = int(input())
for i in range(q):
    cnt = 0
    u, v = map(lambda x: int(x)-1, input().split())
    for j in range(edge_n):
        if colored[j][u] == colored[j][v]:
            cnt += 1
    print(cnt)
    
    
