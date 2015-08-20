def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

INF = 1<<27
V, E = read_list(int)
edge = [[] for _ in range(V)]
for _ in range(E):
    fr, to, cost = map(int, input().split())
    edge[fr].append((to, cost))

dp = [[INF] * V for _ in range(1<<V)]
dp[(1 << V) - 1][0] = 0
for state in reversed(range((1<<V)-1)):
    for v in range(V):
        for to, cost in edge[v]:
            if not (state >> to & 1):
                dp[state][v] = min(dp[state][v], dp[state | 1 << to][to] + cost)
print(dp[0][0] if dp[0][0] != INF else -1)
