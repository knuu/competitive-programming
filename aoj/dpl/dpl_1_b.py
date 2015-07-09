N, maxW = map(int, input().split())
V, W = [], []
for i in range(N):
    v, w = map(int, input().split())
    V.append(v); W.append(w)
dp = [[0]*(maxW+1) for _ in range(2)]
for i in range(N):
    for j in range(maxW+1):
        if j < W[i]:
            dp[(i+1)&1][j] = dp[i&1][j]
        else:
            dp[(i+1)&1][j] = max(dp[i&1][j], dp[i&1][j-W[i]] + V[i])
print(dp[N&1][maxW])
