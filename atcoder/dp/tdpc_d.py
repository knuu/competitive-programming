N, D = map(int, input().split())
d_cnt = [0, 0, 0]
for i, x in enumerate([2, 3, 5]):
    while D % x == 0:
        D //= x
        d_cnt[i] += 1
else:
    if D != 1:
        print(0)
        quit()
c2, c3, c5 = d_cnt
dp = [[[0] * (c5+1) for _ in range(c3+1)] for _ in range(c2+1)]
dp[0][0][0] = 1
for i in range(N):
    _dp = [[[0.0] * (c5+1) for _ in range(c3+1)] for _ in range(c2+1)]
    for j in range(c2 + 1):
        for k in range(c3 + 1):
            for l in range(c5 + 1):
                for nj, nk, nl in [(j, k, l), (min(j+1, c2), k, l), (j, min(k+1, c3), l), (min(j+2, c2), k, l), (j, k, min(l+1, c5)), (min(j+1, c2), min(k+1, c3), l)]:
                    _dp[nj][nk][nl] += dp[j][k][l]
    dp = _dp
print("{:.20f}".format(dp[c2][c3][c5] / (6 ** N)))
