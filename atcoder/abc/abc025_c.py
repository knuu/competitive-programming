from copy import deepcopy
INF = 1<<10

def calc_score(board):
    score = [0] * 2
    for i in range(3):
        for j in range(3):
            if i+1 < 3:
                score[board[i][j] != board[i+1][j]] += B[i][j]
            if j+1 < 3:
                score[board[i][j] != board[i][j+1]] += C[i][j]
    return score
def minmax(cnt, board):
    if cnt == 9:
        return calc_score(board)

    if str(board) in memo:
        return memo[str(board)]
    if cnt % 2 == 0:
        score = [0, INF]
    else:
        score = [INF, 0]

    for i in range(3):
        for j in range(3):
            if board[i][j] == -1:
                new_board = deepcopy(board)
                new_board[i][j] = int(cnt%2)
                new_score = minmax(cnt+1, new_board)
                if cnt % 2 == 0:
                    if score[0] - score[1] < new_score[0] - new_score[1]:
                        score = new_score
                else:
                    if score[0] - score[1] > new_score[0] - new_score[1]:
                        score = new_score
    memo[str(board)] = score
    return score
                
B = [[int(x) for x in input().split()] for _ in range(2)]
C = [[int(x) for x in input().split()] for _ in range(3)]

memo = dict()
board = [[-1] * 3 for _ in range(3)]
print(*minmax(0, board), sep='\n')
