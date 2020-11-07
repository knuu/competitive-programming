def main():
    INF = 10 ** 12
    N, W = map(int, input().split())
    ws, vs = [], []
    for _ in range(N):
        w, v = map(int, input().split())
        ws.append(w)
        vs.append(v)
    sum_v = sum(vs)
    dp = [[INF] * (sum_v + 1) for _ in range(2)]
    dp[0][0] = 0
    for i in range(N):
        now_i, next_i = i & 1, (i+1) & 1
        for j in range(sum_v + 1):
            if j - vs[i] >= 0:
                dp[next_i][j] = min(dp[now_i][j], dp[now_i][j - vs[i]] + ws[i])
            else:
                dp[next_i][j] = dp[now_i][j]
    ans = 0
    for i in range(sum_v + 1):
        if dp[N&1][i] <= W:
            ans = i
    print(ans)


if __name__ == '__main__':
    main()
