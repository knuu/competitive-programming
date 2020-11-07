N, L = map(int, input().split())
Vs, Ds = map(int, input().split())
dist_set = set([0, Ds, L])
cars = [(0, Vs, Ds)]

for _ in range(N):
    X, V, D = map(int, input().split())
    cars.append((X, V, D))
    dist_set.add(X)
    if X + D <= L:
        dist_set.add(X + D)
cars.sort()
dists = sorted(dist_set)
dist_dict = dict()
for i, dist in enumerate(dists):
    dist_dict[dist] = i
assert dist_dict[0] == 0
INF = L + 1
dp = [INF] * len(dist_dict)
dp[0] = 0
for x, v, d in cars:
    start_idx = dist_dict[x]
    end_idx = dist_dict[x + d] if x + d <= L else dist_dict[L]
    if dp[start_idx] == INF:
        continue
    for i in range(start_idx + 1, end_idx + 1):
        dp[i] = min(dp[i], dp[start_idx] + (dists[i] - x) / v)
if dp[-1] == INF:
    print("impossible")
else:
    print("{:.20f}".format(dp[-1]))
