import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
N = int(input())

A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

dp = [0] * (N+1)
for a, b in ((a, b) for a, b in zip(A, B) if a < b):
    for w in range(a, N+1):
        dp[w] = max(dp[w], dp[w-a] + b-a)

M = max(dp) + N
dp = [0] * (M+1)
for a, b in ((a, b) for a, b in zip(A, B) if a > b):
    for w in range(b, M+1):
        dp[w] = max(dp[w], dp[w-b] + a-b)

print(max(dp) + M)
