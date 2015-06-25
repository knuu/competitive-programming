import sys
sys.setrecursionlimit(100000)
def dfs(s):
    if town[s]: 
        return
    else:
        town[s] = True
    for n in road[s]:
        dfs(n)        

n, m = map(int, input().split()) 
road = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    road[a].append(b)
    road[b].append(a)

count = 0
town = [False] * n
for i in range(n):
    if town[i] == False:
        count += 1
        for n in road[i]:
            dfs(i)

print(count-1)


