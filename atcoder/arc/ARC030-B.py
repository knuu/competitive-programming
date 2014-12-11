def dfs(fm, to):
#    print('fm, to',fm+1,to+1)
    cnt = 0
    for n in node[to]:
#        print('node:', n+1)
        if fm == n:
            continue
        if has_jewel(to, n):
#            print('has_jewel: YES')
            cnt += 2 + dfs(to, n)
#    print('')
    return cnt
    
def has_jewel(fm, to):
    if jewel[to] > 0:
        return True
    for n in node[to]:
        if n == fm: continue
        elif jewel[n] > 0:
            return True
        elif has_jewel(to, n):            
            return True
    return False

n, x = map(int, input().split())
x -= 1
jewel = list(map(int, input().split()))

node = [[] for i in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    node[a].append(b)
    node[b].append(a)
print(dfs(x, x))
    




