N = int(input())
P = list(map(int, input().split()))
max_point = sum(P)
dp = [False] * (max_point + 1)
dp[0] = True

for p in P:
    dp_next = dp[:]
    for i in range(max_point):
        if dp[i]: dp_next[i+p] = True
    dp = dp_next[:]
print(dp.count(True))
