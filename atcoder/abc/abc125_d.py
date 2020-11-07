N = int(input())
A = [int(x) for x in input().split()]
dp = [[0, 0] for _ in range(N-1)]
dp[0][0] = A[0] + A[1]
dp[0][1] = -dp[0][0]

for i in range(1, N-1):
    dp[i][0] = max(dp[i-1][0] + A[i+1], dp[i-1][1] + A[i+1])
    dp[i][1] = max(dp[i-1][0] - 2 * A[i] - A[i+1], dp[i-1][1] + 2 * A[i] - A[i+1])

print(max(dp[-1]))
