N = int(input())
S = [list(input()) for _ in range(N)]
S.append(list('o'*N))
ans = 0
for r in range(N):
    for c in range(N-1, -1, -1):
        if S[r][c] == '.':
            ans += 1
            for i in range(c, N):
                S[r+1][i] = 'o'
            break
print(ans)
