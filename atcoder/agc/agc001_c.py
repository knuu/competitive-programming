import sys
sys.setrecursionlimit(5000)


def dfs(v, parent, rest, edge):
    ret = 0
    for c in edge[v]:
        if c != parent:
            ret += dfs(c, v, rest - 1, edge)
    return ret + (rest <= 0)


def main(N, K, edge):
    ans = N
    if K % 2 == 0:
        for v in range(N):
            ans = min(ans, sum(dfs(c, v, K // 2, edge) for c in edge[v]))
    else:
        for v in range(N):
            for c in edge[v]:
                ans = min(ans, dfs(v, c, K // 2 + 1, edge) + dfs(c, v, K // 2 + 1, edge))
    print(ans)


if __name__ == '__main__':
    N, K = map(int, input().split())
    edge = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        edge[u].append(v)
        edge[v].append(u)
    main(N, K, edge)
