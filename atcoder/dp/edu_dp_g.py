import sys
sys.setrecursionlimit(2*10**5)


def dfs(v, graph, memo):
    if memo[v] != -1:
        return memo[v]
    ret = 0
    for c in graph[v]:
        ret = max(ret, dfs(c, graph, memo) + 1)
    memo[v] = ret
    return ret


def main():
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        x, y = map(int, input().split())
        x, y = x - 1, y - 1
        graph[x].append(y)
    memo = [-1] * N
    ans = 0
    for i in range(N):
        ans = max(ans, dfs(i, graph, memo))
    print(ans)


if __name__ == '__main__':
    main()
