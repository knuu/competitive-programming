import sys
sys.setrecursionlimit(2 * 10**5)
mod = 10 ** 9 + 7


def rec(v, p, color, graph, memo):
    if memo[v][color] != -1:
        return memo[v][color]
    ret = 1
    for c in graph[v]:
        if c == p:
            continue
        if color == 0:
            ret *= rec(c, v, 0, graph, memo) + rec(c, v, 1, graph, memo)
        else:
            ret *= rec(c, v, 0, graph, memo)
        ret %= mod
    memo[v][color] = ret
    return ret


def main():
    N = int(input())
    graph = [[] for _ in range(N)]
    for _ in range(N-1):
        x, y = map(int, input().split())
        x, y = x-1, y-1
        graph[x].append(y)
        graph[y].append(x)
    memo = [[-1, -1] for _ in range(N)]
    print((rec(0, -1, 0, graph, memo) + rec(0, -1, 1, graph, memo)) % mod)


if __name__ == '__main__':
    main()
