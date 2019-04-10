import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
sys.setrecursionlimit(10 ** 6)
MAX_COINS = 500 * 100
INF = 10 ** 9


def dfs(idx, coins):
    if idx == N:
        return 0, 0
    elif dp[idx][coins] != -1:
        return dp[idx][coins]

    ret = (0, -INF)

    # not buy
    ret = max(ret, dfs(idx + 1, coins))

    # buy using only bills
    change = (1000 - P[idx] % 1000) % 1000
    cand, money = dfs(idx + 1, coins + change % 500)
    ret = max(ret, (cand + (change >= 500), money - P[idx]))

    # buy using both and get 500
    if (P[idx] + 500) % 1000 <= coins:
        cand, money = dfs(idx + 1, coins - (P[idx] + 500) % 1000)
        ret = max(ret, (cand + 1, money - P[idx]))
    dp[idx][coins] = ret
    # print(idx, coins, ret)
    return ret


while True:
    N = int(input())
    if not N:
        break
    P = [int(input()) for _ in range(N)]

    dp = [[-1] * (MAX_COINS + 1) for _ in range(N + 1)]
    ans, money = dfs(0, 0)
    print(ans, -money)
