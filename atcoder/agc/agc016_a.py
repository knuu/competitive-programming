S = [ord(x) - ord('a') for x in input()]
N = len(S)

ans = N - 1
for i in range(26):
    cnt = 0
    now_S = S[:]
    for j in range(N - 1):
        if all(x == i for x in now_S):
            break
        for k in range(N - j - 1):
            if now_S[k + 1] == i:
                now_S[k] = i
        now_S.pop()
        cnt += 1
    ans = min(ans, cnt)
print(ans)
