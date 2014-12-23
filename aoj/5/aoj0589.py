o={}
for _ in range(int(input())):p,m=input().split();o[p]=o.get(p,0)+int(m)
k=sorted([(len(x),x)for x in o.keys()])
for _,i in k:print(i,o[i])
