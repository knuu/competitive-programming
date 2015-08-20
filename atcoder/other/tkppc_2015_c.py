range = xrange; input = raw_input
N, M = map(int, input().split())
S = int(input())
dp = [0] * S
for _ in range(N):
    T, K = map(int, input().split())
    dp[T-1] += K
ans = 0
for i in range(S-1):
    dp[i+1] += dp[i]
    if dp[i] >= M:
        ans += 1
print(ans)
