N = int(input())
A = [int(x) for x in input().split()]
dp = [[False] * (N + 1) for _ in range(N + 1)]
dp[0][0] = True
for i in range(N):
    if A[i] % 2 == 1:
        for j in range(N):
            for k in range(i + 1):
                if (k - i + 1) % 2 == 1 and A[k] % 2 == 1 and dp[k][j]:
                    dp[i + 1][j + 1] = True
print("Yes" if any(dp[-1][i] for i in range(1, N + 1, 2)) else "No")
