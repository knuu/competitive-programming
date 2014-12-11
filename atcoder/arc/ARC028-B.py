num, k = map(int, input().split())
dic ={}
yearlist = list(map(int, input().split()))

for cnt, y in enumerate(yearlist):
    dic[y] = cnt + 1

sublist = yearlist[:k]
sublist.sort()

print(dic[sublist[k-1]])

def n_insert(n, l):
    if n > l[len(l)-1]:
        l.append(n)
        return l
    for i in range(len(l)):
        if n < l[i]:
            l.insert(i, n)
            break
    return l

for i in range(k, len(yearlist)):
    n_insert(yearlist[i], sublist)
    print(dic[sublist[k-1]])
    
    
