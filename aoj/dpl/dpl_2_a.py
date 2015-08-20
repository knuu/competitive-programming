def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

def rec(state, v):
    if dp[state][v] >= 0:
        return dp[state][v]
    if (1 << V) - 1 == state and v == 0:
        dp[state][0] = 0
        return 0

    ret = INF
    for to, cost in edge[v]:
        if not (state >> to & 1):
            ret = min(ret, rec(state | 1 << to, to) + cost)
    dp[state][v] = ret
    return ret

INF = 1<<27
V, E = read_list(int)
edge = [[] for _ in range(V)]
for _ in range(E):
    fr, to, cost = map(int, input().split())
    edge[fr].append((to, cost))

dp = [[-1] * V for _ in range(1<<V)]
print(dp[0][0] if rec(0, 0) != INF else -1)
