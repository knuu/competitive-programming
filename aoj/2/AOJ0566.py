score = [list(map(lambda x: int(x) - 1 , input().split())) for _ in range(int(n*(n-1)/2))]

points = [0 for _ in range(n)]

for a,b,c,d in score:
    if c > d:
        points[a] += 3
    elif c < d:
        points[b] += 3
    else:
        points[a] += 1
        points[b] += 1
        
rank = sorted(points)
rank.reverse()
 
for p in points: 
    print(rank.index(p) + 1)
