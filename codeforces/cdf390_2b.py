N = 4
board = [input() for _ in range(4)]
for i in range(N):
    for j in range(N):
        cand = []
        if j + 2 < N:
            cand.append([board[i][j+k] for k in range(3)])
        if i + 2 < N:
            cand.append([board[i+k][j] for k in range(3)])
        if i + 2 < N and j + 2 < N:
            cand.append([board[i+k][j+k] for k in range(3)])
        if i + 2 < N and j - 2 >= 0:
            cand.append([board[i+k][j-k] for k in range(3)])
        for row in cand:
            for k in range(3):
                if all(c == 'x' if i != k else c == '.' for i, c in enumerate(row)):
                    print("YES")
                    quit()
print("NO")
