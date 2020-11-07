import sys
sys.setrecursionlimit(10 ** 5 + 100)

def dfs(i, type_):
    if i >= N:
        return 0
    if dp[i][type_] != -1:
        return dp[i][type_]
    ret = 0
    for t in range(3):
        if t == type_:
            continue
        ret = max(ret, dfs(i + K, t))
    dp[i][type_] = ret + ((type_ + 1) % 3 == T[i]) * score[type_]
    return dp[i][type_]


N, K = map(int, input().split())
score = [int(x) for x in input().split()]
dic = {"r": 0, "s": 1, "p": 2}
T = [dic[x] for x in input()]
dp = [[-1] * 3 for _ in range(N)]
ans = 0
for i in range(K):
    ans += max(dfs(i, t) for t in range(3))
print(ans)
