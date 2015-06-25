from copy import deepcopy

def reclaim(i, j):
    island[i][j] = 1
    if i > 0 and island[i-1][j] == 'o':
        reclaim(i-1, j)
    if j > 0 and island[i][j-1] == 'o':
        reclaim(i, j-1)
    if i < 9 and island[i+1][j] == 'o':
        reclaim(i+1, j)
    if j < 9 and island[i][j+1] == 'o':
        reclaim(i, j+1)
    if check():
        return True
    else:
        return False

def check():
    for i in range(10):
        for j in range(10):
            if island[i][j] == 'o':
                return False
    return True

table = [list(input()) for _ in range(10)]

island = deepcopy(table)
flag = False
for i in range(10):
    for j in range(10):
        if table[i][j] == 'x':
            reclaim(i, j)
            if check():
                flag = True
                break
            island = deepcopy(table)
    if flag:
        break

if flag:
    print("YES")
else:
    print("NO")
