INF = 10 ** 9
def calc(group):
    L = len(group)
    ret = 0
    for i in range(L):
        for j in range(i+1, L):
            ret += adj[group[i]][group[j]]
    return ret


def dfs(i, A, B, C):
    if i == N:
        return calc(A) + calc(B) + calc(C)
    ans = -INF
    A.append(i)
    ans = max(ans, dfs(i+1, A, B, C))
    A.pop()
    B.append(i)
    ans = max(ans, dfs(i+1, A, B, C))
    B.pop()
    C.append(i)
    ans = max(ans, dfs(i+1, A, B, C))
    C.pop()
    return ans


N = int(input())
adj = [[0] * N for _ in range(N)]
for i in range(N-1):
    row = [int(x) for x in input().split()]
    assert(len(row) == N - i - 1)
    for j, a in enumerate(row):
        adj[i][i+j+1] = adj[i+j+1][i] = a
print(dfs(0, [], [], []))
