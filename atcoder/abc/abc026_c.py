def dfs(s):
    if not edge[s]:
#        print(s, 1)
        return 1
    subords = []
#    print(s, edge[s])
    for to in edge[s]:
        subords.append(dfs(to))
#    print(s, max(subords) + min(subords) + 1)
    return max(subords) + min(subords) + 1
N = int(input())
edge = [[] for _ in range(N)]
for i in range(1, N):
    edge[int(input()) - 1].append(i)
print(dfs(0))
