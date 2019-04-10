N = int(input())
S = [x == '1' for x in input()]
S.append(0)
ans = 0
now = 0


def dp(arr):
    L = len(arr)
    if L == 1:
        return 0
    dp = [[0] * 4 for _ in range(L)]
    dp[0] = [-1, arr[0], -1, 0]
    ret = max(dp[0])
    for i in range(L - 1):
        dp[i + 1][0] = dp[i][3] + arr[i + 1]
        if dp[i][0] != -1 and arr[i] > 1:
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + arr[i + 1] - 1)
        if dp[i][2] != -1 and arr[i] > 1:
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] + arr[i + 1])
        dp[i + 1][1] = dp[i][3] + arr[i + 1]
        if dp[i][0] != -1 and i != L - 2:
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + arr[i + 1])
        if dp[i][1] != -1 and arr[i + 1] > 1 and i != L - 2:
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + arr[i + 1] - 1)
        if dp[i][2] != -1 and i != L - 2:
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + arr[i + 1])
        dp[i + 1][2] = dp[i][1]
        dp[i + 1][3] = max([dp[i][0], dp[i][3], dp[i][2]])
        ret = max(ret, max(dp[i + 1]))
    #print(*dp, sep='\n')
    return ret


while now < N:
    if S[now] == 1:
        left = now
        cnt_1 = 1
        prev = 1
        now += 1
        arr = []
        while now < N and (prev != 0 or S[now] != 0):
            if S[now] == 0:
                arr.append(cnt_1)
                cnt_1 = 0
            else:
                cnt_1 += 1
            prev = S[now]
            now += 1
        if cnt_1:
            arr.append(cnt_1)
        if now == N:
            if prev == 0:
                right = N - 2
            else:
                right = N - 1
        else:
            right = now - 2
        #print('#', arr)
        ans += dp(arr)
        while now < N and S[now] == 0:
            now += 1
    else:
        now += 1
print(ans)
