import sys
if sys.version[0] == '2':
    input, range = raw_input, xrange

S = input()
N = len(S)

dp = [[0] * (N+1) for _ in range(N+1)] # [left, right)

for w in range(3, N + 1):
    for left in range(N - w + 1):
        right = left + w
        for mid in range(left + 1, right):
            dp[left][right] = max(dp[left][right], dp[left][mid] + dp[mid][right])
        if S[left] == S[right - 1] == 'i':
            for mid in range(left + 1, right - 1):
                if S[mid] == 'w' and (dp[left + 1][mid] + dp[mid + 1][right - 1]) * 3 == right - left - 3:
                    dp[left][right] = (right - left) // 3
                    break
print(dp[0][N])
