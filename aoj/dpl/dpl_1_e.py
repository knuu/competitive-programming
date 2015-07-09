s1 = input()
s2 = input()
dp = [[i+j for j in range(len(s2)+1)] for i in range(len(s1)+1)]

for i in range(len(s1)):
    for j in range(len(s2)):
        dp[i+1][j+1] = min(dp[i][j+1] + 1, dp[i+1][j] + 1, dp[i][j] + 1 * (s1[i] != s2[j]))
print(dp[len(s1)][len(s2)])
