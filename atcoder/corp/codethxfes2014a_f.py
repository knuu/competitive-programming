N, M = map(int, input().split())
E = [[] for _ in range(N)]
for _ in range(M):
    A, B = map(lambda x:int(x)-1, input().split())
    E[B].append(A)

check = [False] * N
def dfs(fr):
    if check[fr]: return 0
    check[fr] = True
    ret = 1
    for to in E[fr]:
        ret += dfs(to)
    return ret

print(dfs(0))
