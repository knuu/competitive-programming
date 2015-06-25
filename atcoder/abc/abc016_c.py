n, m = map(int, input().split())
friend = [[], [], [], [], [], [], [], [], [], []]

for i in range(m):
    a,b = map(int, input().split())
    friend[a-1].append(b-1)
    friend[b-1].append(a-1)

for i in range(n):
    c = []
    for j in friend[i]:
        c.extend(friend[j])
    c = set(c)
    if i in c: c.remove(i)
    for j in friend[i]:
        if j in c: c.remove(j)
    print(len(c))

