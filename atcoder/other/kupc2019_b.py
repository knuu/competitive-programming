N, M, W = map(int, input().split())
ws, vs = [], []
for i in range(N):
    w, v = map(int, input().split())
    ws.append(w)
    vs.append(v)

def dfs(v):
    ret_w, ret_v = ws[v], vs[v]
    if used[v]:
        return 0, 0
    used[v] = True
    for c in edges[v]:
        tmp_w, tmp_v = dfs(c)
        ret_w += tmp_w
        ret_v += tmp_v
    return ret_w, ret_v


edges = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)
used = [False] * N
wws, vvs = [], []
for i in range(N):
    if not used[i]:
        w, v = dfs(i)
        wws.append(w)
        vvs.append(v)

dp = [[0] * (W + 1) for _ in range(len(wws) + 1)]
for i in range(len(wws)):
    for w in range(W + 1):
        if w - wws[i] >= 0:
            dp[i+1][w] = max(dp[i][w], dp[i][w-wws[i]] + vvs[i])
        else:
            dp[i+1][w] = dp[i][w]

print(max(dp[-1]))
