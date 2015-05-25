while True:
    N = int(input())
    if N == 0: break
    W, H = map(int, input().split())
    board = [[0]*W for _ in range(H)]
    for i in range(N):
        x, y = map(lambda x:int(x)-1, input().split())
        board[y][x] = 1
    w, h = map(int, input().split())
    ans = 0
    rowSums = []
    for row in board:
        rowSum = [sum(row[:w])]
        for i in range(W-w):
            rowSum.append(rowSum[i]-row[i]+row[i+w])
        rowSums.append(rowSum)
    areaSums = [[0]*(W-w+1) for _ in range(H-h+1)]
    for i in range(len(rowSums[0])):
        areaSums[0][i] = sum(rowSums[j][i] for j in range(h))
        for j in range(H-h):
            areaSums[j+1][i] = areaSums[j][i] - rowSums[j][i] + rowSums[j+h][i]
    print(max([max(row) for row in areaSums]))
            
