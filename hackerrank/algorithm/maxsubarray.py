for _ in range(int(input())):
    N = int(input())
    dp = [[0, 0] for _ in range(N+1)]
    array = [int(x) for x in input().split()]
    for i, a in enumerate(array):
        dp[i+1][1] = max(dp[i+1][1], dp[i][1] + a)
        dp[i+1][0] = max(dp[i][0], dp[i+1][1])
    non_c = sum(x for x in array if x > 0)
    if non_c:
        print(dp[N][0], non_c)
    else:
        m = max(array)
        print(m, m)
