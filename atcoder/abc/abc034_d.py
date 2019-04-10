N, K = map(int, input().split())
salt = [[int(x) for x in input().split()] for _ in range(N)]

left, right = 0.0, 100.0
for _ in range(100):
    mid = (left + right) / 2
    if sum(sorted([w * (p - mid) for w, p in salt], reverse=True)[:K]) >= 0:
        left = mid
    else:
        right = mid
print(left)
