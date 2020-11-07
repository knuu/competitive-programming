import sys
sys.setrecursionlimit(10**6)
N, M = map(int, input().split())
edge = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edge[a].append(b)
    edge[b].append(a)
color = [-1] * N
def dfs(v, c):
    if color[v] != -1:
        return color[v] == c
    else:
        color[v] = c
        ret = True
        for w in edge[v]:
            ret &= dfs(w, c ^ 1)
        return ret

if dfs(0, 0) == False:
    print(N * (N - 1) // 2 - M)
else:
    c1 = color.count(0)
    c2 = color.count(1)
    assert(c1 + c2 == N)
    print(c1 * c2 - M)
