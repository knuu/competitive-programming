A = [[int(x) for x in input().split()] for _ in range(4)]
for i in range(4):
    for j in range(4):
        if (i+1 < 4 and A[i][j] == A[i+1][j]) or (j+1 < 4 and A[i][j] == A[i][j+1]):
            print('CONTINUE')
            exit(0)
print('GAMEOVER')
