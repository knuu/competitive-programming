import itertools
N = int(input())
C = input()
comm = [''.join(x) for x in itertools.product('ABXY', repeat=2)]
ans = N
for i in range(16):
    for j in range(i+1, 16):
        L, R = comm[i], comm[j]
        dp = [0] * (N+1)
        for k in range(N):
            if k > 0:
                dp[k+1] = min(dp[k] + 1, dp[k-1] + 2 - (C[k-1:k+1] in [L, R]))
            else:
                dp[k+1] = dp[k] + 1
        ans = min(ans, dp[N])
print(ans)
