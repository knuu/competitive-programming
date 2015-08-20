range = xrange; input = raw_input
import sys
sys.setrecursionlimit(1000000)

def dfs(fr):
    if used[fr]:
        return 0, fr

    used[fr] = True
    dist, leaf = 0, fr

    for to in edge[fr]:
        if not used[to]:
            d, l = dfs(to)
            if d > dist:
                dist, leaf = d, l
    return dist+1, leaf

N = int(input())
edge = [[] for _ in range(N)]
for _ in range(N-1):
    A, B = map(lambda x:int(x)-1, input().split())
    edge[A].append(B)
    edge[B].append(A)

used = [False] * N
s = dfs(0)[1]
used = [False] * N
print s+1, dfs(s)[1]+1

