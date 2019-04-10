import sys
sys.setrecursionlimit(10**6)
if sys.version[0] == '2':
    range, input = xrange, raw_input
N = int(input())
edge = [[] for _ in range(N)]
ans = [0] * N
for i in range(N-1):
    edge[int(input())].append(i+1)


def dfs(v):
    child = 1
    for c in edge[v]:
        c_ret = dfs(c)
        child += c_ret
        ans[v] = max(ans[v], c_ret)
    ans[v] = max(ans[v], N - child)
    return child

dfs(0)
print(*ans, sep='\n')
