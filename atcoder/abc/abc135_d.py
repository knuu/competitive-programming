S = input()
dp = [[0] * 13 for _ in range(2)]

mod = 10**9 + 7
dp[0][0] = 1
pow10 = 1
for i, s in enumerate(S[::-1]):
    now_idx, next_idx = i & 1, (i + 1) & 1
    dp[next_idx] = [0] * 13
    if s == '?':
        for j in range(13):
            for k in range(10):
                next_mod = (j + k * pow10) % 13
                dp[next_idx][next_mod] += dp[now_idx][j]
                dp[next_idx][next_mod] %= mod
    else:
        k = int(s)
        for j in range(13):
            next_mod = (j + k * pow10) % 13
            dp[next_idx][next_mod] += dp[now_idx][j]
            dp[next_idx][next_mod] %= mod
    pow10 = (pow10 * 10) % 13
print(dp[len(S) & 1][5])
