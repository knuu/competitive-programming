N = int(input())
if N == 1:
    print(1)
    quit()
points = []
for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))
diff = dict()
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        x1, y1 = points[i]
        x2, y2 = points[j]
        pq = x1-x2, y1-y2
        diff[pq] = diff.get(pq, 0) + 1
val, key = max((v, k) for k, v in diff.items())
print(N-val)
