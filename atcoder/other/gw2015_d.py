import sys
H, W, Q = map(int, input().split())
h = [[0] * W for _ in range(H)]
for i in range(H):
    for j in range(W):
        print('1 1 {} {}'.format(i+1, j+1))
        sys.stdout.flush()
        h[i][j] = int(input())
        
for _ in range(Q):
    Si, Sj, Ti, Tj = map(lambda x: int(x)-1 ,input().split())
    if Si > Ti:
        Si, Ti = Ti, Si
        Sj, Tj = Tj, Sj
    if Sj < Tj:
        print(h[Ti][Tj] - h[Si][Sj])
    else:
        print(h[Ti][Tj] + h[Si][Sj] - 2 * h[Si][Tj])
    sys.stdout.flush()
