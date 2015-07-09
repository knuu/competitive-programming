n = int(input())
s = input()
c = list(map(int, input().split()))
pal = [[0 for _ in range(n)] for _ in range(n)]
for k in range(n):
    i, j = k, k
    while i >= 0 and j < n and s[i] == s[j]:
        pal[i][j] = True
        i -= 1
        j += 1
    i, j = k, k+1
    while i >= 0 and j < n and s[i] == s[j]:
        pal[i][j] = True
        i -= 1
        j += 1
dp = [(10 ** 5) * n for _ in range(n+1)]
dp[0] = 0
for i in range(n):
    for j in range(i+1):
        if pal[j][i]:
            dp[i+1] = min(dp[i+1], dp[j] + c[i-j])
print(dp[n])
