N, R = map(int, input().split())
board = list(input())
ans = 0
for i in range(N-1, -1, -1):
    if board[i] == '.':
        ans += max(0, i-R+1)
        break

i = 0
while i < N:
    if board[i] == '.':
        ans += 1
        i += R
    else:
        i += 1
print(ans)
