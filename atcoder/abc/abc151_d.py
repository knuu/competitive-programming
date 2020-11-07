H, W = map(int, input().split())
N = H * W
board = [[int(x == "#") for x in input()] for _ in range(H)]
INF = N ** 2
A = [[INF] * N for _ in range(N)]
for i in range(N):
    A[i][i] = 0
drc = [(-1, 0), (1, 0), (0, 1), (0, -1)]
for r in range(H):
    for c in range(W):
        for dr, dc in drc:
            nr, nc = r + dr, c + dc
            if nr < 0 or H <= nr or nc < 0 or W <= nc:
                continue
            if board[nr][nc] == 1:
                continue
            A[r * W + c][nr * W + nc] = 1
for k in range(N):
    for i in range(N):
        for j in range(N):
            A[i][j] = min(A[i][j], A[i][k] + A[k][j])
ans = 0
for sr in range(H):
    for sc in range(W):
        if board[sr][sc]:
            continue
        for gr in range(H):
            for gc in range(W):
                if board[gr][gc]:
                    continue
                ans = max(ans, A[sr*W+sc][gr*W+gc])
print(ans)
