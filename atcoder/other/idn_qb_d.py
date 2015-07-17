N, C = map(int, input().split())
bucket = [[] for _ in range(C)]
for i, a in enumerate(int(x)-1 for x in input().split()):
    bucket[a].append(i)

for l in bucket:
    prev = -1
    ans = 0
    for pos in l:
        ans += (pos-prev) * (N - pos)
        prev = pos
    print(ans)
