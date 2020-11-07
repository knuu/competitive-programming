def main():
    S, T = input(), input()
    L_S, L_T = len(S), len(T)
    dp = [[(0, (0, 0)) for _ in range(L_T+1)] for _ in range(L_S+1)]
    for i in range(L_S):
        for j in range(L_T):
            if S[i] == T[j]:
                dp[i+1][j+1] = (dp[i][j][0] + 1, (-1, -1))
            else:
                dp[i+1][j+1] = max((dp[i+1][j][0], (0, -1)), (dp[i][j+1][0], (-1, 0)))
    i, j = L_S, L_T
    ans = []
    while i > 0 and j > 0:
        di, dj = dp[i][j][1]
        if di != 0 and dj != 0:
            ans.append(S[i-1])
        i, j = i + di, j + dj
    print(''.join(ans[::-1]))



if __name__ == '__main__':
    main()
