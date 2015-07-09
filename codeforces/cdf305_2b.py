def condMax(row):
    flag = False
    ret, cnt = 0, 0
    for x in row:
        if flag == False and x == 1:
            cnt = 1
            flag = True
        elif flag == True and x == 1:
            cnt += 1
        elif flag == True and x == 0:
            ret = max(cnt, ret)
            flag = False
    if flag == True:
        ret = max(cnt, ret)
    return ret

N, M, Q = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
rows = [condMax(row[:]) for row in board]
    
ans = max(rows)
for i in range(Q):
    i, j = map(lambda x:int(x)-1, input().split())
    board[i][j] ^= 1
    rows[i] = condMax(board[i][:])
    ans = max(rows)
    print(ans)
