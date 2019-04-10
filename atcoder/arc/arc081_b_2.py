N = int(input())
board = [input(), input()]

if N == 1:
    print(3)
    quit()


if board[0][0] == board[0][1]:
    cnt, prev = 6, 0
else:
    cnt, prev = 3, 1
mod = 10 ** 9 + 7

for i in range(1, N):
    if board[0][i] == board[0][i - 1]:
        continue
    elif i < N - 1 and board[0][i] == board[0][i + 1] and prev == 0:
        cnt *= 3
        cnt %= mod
    elif i < N - 1 and board[0][i] == board[0][i + 1] and prev == 1:
        cnt *= 2
        cnt %= mod
        prev = 0
    elif board[0][i] == board[1][i] and prev == 0:
        prev = 1
    else:
        cnt *= 2
        cnt %= mod
print(cnt)
