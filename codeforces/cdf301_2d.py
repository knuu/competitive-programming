r, s, p = map(int, input().split())
dp = [[[0] * (p+1) for _ in range(s+1)] for _ in range(r+1)]
dp[r][s][p] = 1
def nCk(n, k):
    if n <= k:
        return 1
    res = 1
    for i in range(k):
        res *= n-i
    for i in range(k):
        res //= (i+1)
    return res

C = [nCk(i, 2) for i in range(r+s+p+1)]
for ri in range(r, -1, -1):
    for si in range(s, -1, -1):
        for pi in range(p, -1, -1):
            t = ri * si + si * pi + pi * ri
            if t == 0: continue
            if ri > 0:
                dp[ri-1][si][pi] += dp[ri][si][pi] * ri * pi / t
            if si > 0:
                dp[ri][si-1][pi] += dp[ri][si][pi] * ri * si / t
            if pi > 0:
                dp[ri][si][pi-1] += dp[ri][si][pi] * si * pi / t
        
        
r_sum = sum([dp[ri][0][0] for ri in range(r+1)])
s_sum = sum([dp[0][si][0] for si in range(s+1)])
p_sum = sum([dp[0][0][pi] for pi in range(p+1)])
print(r_sum, s_sum, p_sum)
