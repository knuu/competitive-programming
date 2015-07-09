N = int(input())
board = ''
for i in range(N): board += input()
board = list(board)
R = board.count('R')
B = board.count('B')
if R > B:
    print('TAKAHASHI')
elif R < B:
    print('AOKI')
else:
    print('DRAW')
