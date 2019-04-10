N, S = int(input()), input()
ans = N
for i in range(1, N):
    s1, s2 = S[:i], S[i:]
    dp = [[0]*(len(s2)+1) for _ in range(len(s1)+1)]
    for j in range(len(s1)):
        for k in range(len(s2)):
            if (s1[j] == s2[k]):
                dp[j+1][k+1] = max([dp[j][k] + 1, dp[j][k+1], dp[j+1][k]])
            else:
                dp[j+1][k+1] = max(dp[j][k+1], dp[j+1][k])
    ans = min(ans, N - 2 * dp[len(s1)][len(s2)])
print(ans)
