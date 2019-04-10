import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
while True:
    N = int(input())
    if not N:
        break
    W = [int(x) for x in input().split()]
    dp = [[0] * N for _ in range(N)]
    for i in range(N-1):
        if abs(W[i] - W[i + 1]) <= 1:
            dp[i][i + 1] = 2
    for w in range(3, N + 1):
        for left in range(N - w + 1):
            # [left, right]
            right = left + w - 1
            if w - 2 == dp[left + 1][right - 1] and abs(W[left] - W[right]) <= 1:
                dp[left][right] = w
                continue
            for mid in range(left + 1, right):
                m = dp[left][mid] + dp[mid + 1][right]
                if m > dp[left][right]:
                    dp[left][right] = m
    print(dp[0][N-1])
