import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
ans = []
idx = [x for x in reversed(range(300))]
for i in range(299):
    idx[i + 1] += idx[i]

def dec(l, r):
    return idx[l] + r - l

while True:
    N = int(input())
    if not N:
        break
    W = [int(x) for x in input().split()]
    dp = [0] * (N * (N + 1) // 2)
    for i in range(N-1):
        if abs(W[i] - W[i + 1]) <= 1:
            dp[dec(i, i + 1)] = 2
    for w in range(3, N + 1):
        for left in range(N - w + 1):
            # [left, right]
            right = left + w - 1
            if w - 2 == dp[dec(left + 1, right - 1)] and abs(W[left] - W[right]) <= 1:
                dp[dec(left, right)] = w
                continue
            for mid in range(left + 1, right):
                m = dp[dec(left, mid)] + dp[dec(mid + 1, right)]
                if m > dp[dec(left, right)]:
                    dp[dec(left, right)] = m
    print(dp[dec(0, N-1)])
