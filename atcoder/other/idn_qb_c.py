import heapq
N = int(input())
used = [False] * N
edge = [[] for _ in range(N)]
for i in range(N-1):
    a, b = map(lambda x:int(x)-1, input().split())
    edge[a].append(b)
    edge[b].append(a)
ans = []
pque = [0]
while pque:
    top = heapq.heappop(pque)
    ans.append(top+1)
    used[top] = True
    for to in edge[top]:
        if not used[to]:
            heapq.heappush(pque, to)
print(*ans)
