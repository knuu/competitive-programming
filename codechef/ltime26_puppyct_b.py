for _ in range(int(input())):
    N, K = map(int, input().split())
    if K == 0:
        print(N * N)
        continue
    if K <= 1:
        x, y = map(lambda x: int(x)-1, input().split())
        plus = N - abs(N-(x+y)-1)
        minus = N - abs(x-y)
        print(N*N - plus - minus + 1)
        continue
    board = [[True] * N for _ in range(N)]

    for _ in range(K):
        x, y = map(lambda x: int(x)-1, input().split())
        nx, ny = x, y
        while 0 <= nx < N and 0 <= ny < N:
            board[nx][ny] = False
            nx += 1; ny -= 1
        nx, ny = x, y
        while 0 <= nx < N and 0 <= ny < N:
            board[nx][ny] = False
            nx -= 1; ny += 1
        nx, ny = x, y
        while 0 <= nx < N and 0 <= ny < N:
            board[nx][ny] = False
            nx -= 1; ny -= 1
        nx, ny = x, y
        while 0 <= nx < N and 0 <= ny < N:
            board[nx][ny] = False
            nx += 1; ny += 1
    
    print(sum(sum(row) for row in board))
