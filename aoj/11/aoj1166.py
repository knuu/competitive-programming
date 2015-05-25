import collections
while True:
    W, H = map(int, input().split())
    if (W, H) == (0, 0): break
    cdoor, rdoor = [], []
    cdoor.append(list(map(int, input().split())))
    for _ in range(H-1):
        rdoor.append(list(map(int, input().split())))
        cdoor.append(list(map(int, input().split())))
    
    maze = [[-1 for _ in range(W)] for _ in range(H)]
    maze[0][0] = 1
    que = collections.deque()
    que.append((0, 0))
    drc = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    while maze[H-1][W-1] == -1 and len(que) > 0:
        r, c = que.popleft()
        for dr, dc in drc:
            nr, nc = r+dr, c+dc
            if 0 <= nr < H and 0 <= nc < W and ((dc == 0 and rdoor[min(nr, nr-dr)][c] == 0) or (dr == 0 and cdoor[r][min(nc, nc-dc)] == 0)) and maze[nr][nc] == -1:
                maze[nr][nc] = maze[r][c] + 1
                que.append((nr, nc))
    print(maze[H-1][W-1] if maze[H-1][W-1] != -1 else 0)
