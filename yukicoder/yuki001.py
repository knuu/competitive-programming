from queue import PriorityQueue as PQueue
N = int(input())
C = int(input())
V = int(input())
S = list(map(lambda x: int(x)-1, input().split()))
T = list(map(lambda x: int(x)-1, input().split()))
Y = list(map(int, input().split()))
M = list(map(int, input().split()))
E = [[] for _ in range(N)]
for f, t, cost, time in zip(S, T, Y, M):
    E[t].append((f, cost, time))
INF = 10**7
dp = [[INF] * (C+1) for _ in range(N)]
for i in range(C+1):
    dp[0][i] = 0
for t in range(N):
    for j in range(C+1):
        for f, cost, time in E[t]:
            if j >= cost and dp[t][j] > dp[f][j-cost] + time:
                dp[t][j] = dp[f][j-cost] + time
print(min(dp[N-1]) if min(dp[N-1]) != INF else -1)
