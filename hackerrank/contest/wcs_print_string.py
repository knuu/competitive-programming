for _ in range(int(input())):
    N, A, B = map(int, input().split())
    S = input()
    prev = [0] * N
    l = 0
    for i in range(N):
        while (S[l:i+1] not in S[:l]):
            l += 1
        prev[i] = l-1 if l < i+1 else -1
    dp = [0] * (N + 1)
    dp[0] = 0
    for i in range(N):
        if prev[i] == -1:
            dp[i+1] = dp[i] + A
        else:
            dp[i+1] = min(dp[i] + A, dp[prev[i] + 1] + B)
    print(dp[N])
