from collections import defaultdict
N, M, K = map(int, input().split())

rows = defaultdict(list)

for _ in range(K):
    r, c1, c2 = map(int, input().split())
    rows[r].append((c1, c2))

ans = N * M
for k in rows.keys():
    rows[k].sort()
for row in rows.values():
    end = 0
    for c1, c2 in row:
        if end < c1:
            ans -= c2 - c1 + 1
        elif c1 <= end < c2:
            ans -= c2 - end
        end = max(end, c2)
print(ans)
