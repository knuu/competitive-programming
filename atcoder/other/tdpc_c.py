K = int(input())
N = 1 << K
R = [int(input()) for _ in range(N)]


def winp(rp, rq):
    return 1. / (1 + 10 ** ((rq - rp) / 400.))

dp = [1.0] * N
for i in range(K):
    _dp = [0.0] * N
    for l in range(0, N, 1 << (i + 1)):
        for j in range(l, l + (1 << (i + 1))):
            start = l + (1 << i) if j - l < (1 << i) else l
            for k in range(start, start + (1 << i)):
                _dp[j] += dp[j] * dp[k] * winp(R[j], R[k])
    dp = _dp
print(*['{:.20f}'.format(x) for x in dp], sep='\n')
