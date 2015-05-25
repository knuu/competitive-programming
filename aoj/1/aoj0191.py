while True:
    N, M = map(int, raw_input().split())
    if (N, M) == (0, 0): break
    fert = [map(float, raw_input().split()) for _ in range(N)]
    dp = [[0]*N for _ in range(M)]
    for i in range(N): dp[0][i] = 1.0
    for i in range(M-1):
        for j in range(N):
            dp[i+1][j] = max([dp[i][k]*fert[k][j] for k in range(N)])
    print('{:.2f}'.format(round(max(dp[M-1]), 2)))
