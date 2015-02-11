n = map(int, input().split())
l = list(map(int, input().split()))
ans = 1000
for i in range(1,len(l)-1):
    li = l[:]
    li.remove(l[i])
    m = 0
    for j in range(len(li)-1):
        m = max(li[j+1] - li[j], m)
    ans = min(m, ans)

print(ans)

                   
