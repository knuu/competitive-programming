def main():
    N, W = map(int, input().split())
    dp = [[0] * (W + 1) for _ in range(2)]
    ws, vs = [], []
    for _ in range(N):
        w, v = map(int, input().split())
        ws.append(w)
        vs.append(v)

    for i in range(N):
        now_i, next_i = i & 1, (i+1) & 1
        for j in range(W+1):
            if j - ws[i] >= 0:
                dp[next_i][j] = max(dp[now_i][j], dp[now_i][j-ws[i]] + vs[i])
            else:
                dp[next_i][j] = dp[now_i][j]
    print(max(dp[N & 1]))


if __name__ == '__main__':
    main()
