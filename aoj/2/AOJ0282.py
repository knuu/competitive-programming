n, r, l = map(int, input().split())
point, time = [], []
rev = {0: []}
for i in range(n):
    point.append(0)
    time.append(0)
    rev[0].append(i)

now, tv, tmax = 0, 0, 0
for i in range(r):
    d, t, x = map(int, input().split())
    time[tv] += t - now
    now = t
    m = point[d-1]
    rev[point[d-1]].remove(d-1)
    point[d-1] += x
    if point[d-1] in rev:
        rev[point[d-1]].append(d-1)
    else:
        rev[point[d-1]] = [d-1]
    if tv != d-1: 
        if point[tv] == point[d-1]:
            tv = min(tv, d-1)
        elif point[tv] < point[d-1]:
            tv = d-1
    elif x < 0:
        if rev[m] != []:
            tv = min(rev[m])
        else:
            tv = min(rev[max(point)])

time[tv] += l - now

m = max(time)
i = 0
while True:
    if time[i] == m:
        print(i+1)
        break
    i += 1
