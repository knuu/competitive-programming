n, q = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(q)]

a, b, s, t = 0, 1, 2, 3
for i in range(q):
    fare = 0
    if l[i][b] <= l[i][s] or l[i][t] <= l[i][a]:
        fare = l[i][t] - l[i][s]
    else:
        if l[i][s] < l[i][a]:
            fare += l[i][a] - l[i][s]
        if l[i][b] < l[i][t]:
            fare += l[i][t] - l[i][b]
    print(fare*100)
