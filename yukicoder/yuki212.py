P, C = map(int, input().split())
dp = [{} for _ in range(P+1)]
dp[0][1] = 1
for i in range(P):
    for k in [2,3,5,7,11,13]:
        for j in dp[i].keys():
            dp[i+1][j*k] = dp[i+1].get(j*k, 0) + dp[i][j]

dp2 = [{} for _ in range(C+1)]
for k in dp[P].keys(): dp2[0][k] = dp[P][k]
for i in range(C):
    for k in [4,6,8,9,10,12]:
        for j in dp2[i].keys():
            dp2[i+1][j*k] = dp2[i+1].get(j*k, 0) + dp2[i][j]

ans = 0
for key, cnt in dp2[C].items():
    ans += key * cnt
print(ans / (6**(P+C)))
