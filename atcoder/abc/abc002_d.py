from copy import deepcopy
N, M = map(int, input().split())
E = [[] for _ in range(N)]
for i in range(M):
    x, y = map(lambda x:int(x)-1, input().split())
    E[x].append(y)
    E[y].append(x)
ans = 0
for mask in range(2**N):
    faction = ''
    for x in range(N):
        faction += '1' if mask&(1<<x) else '0'
    flag = True
    for cnt, i in enumerate(faction):
        if int(i) == 1:
            for j in range(cnt+1, N):
                if faction[j] == '1' and j not in E[cnt]:
                    flag = False
    if flag: ans = max(ans, faction.count('1'))
print(ans)
                
