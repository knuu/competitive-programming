def dfs(x, y):
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if abs(dx) + abs(dy) == 2 or abs(dx) + abs(dy) == 2:
                continue
            next_x, next_y = x + dx, y + dy
            if 0 <= next_x < H and 0 <= next_y < W and isVisited[next_x][next_y] == 0 and tile[next_x][next_y] == '.':
                isVisited[next_x][next_y] = 1
                dfs(next_x, next_y)
                
                

while True:
    W, H = map(int, raw_input().split())
    if W == 0 and H == 0: break
    tile = [raw_input() for _ in range(H)]
    ans = 0
    isVisited = [[0]*W for _ in range(H)]
    for cnt, t in enumerate(tile):
        if '@' in t:
            sx = cnt
            sy = t.index('@')
            break
    isVisited[sx][sy] = 1
    dfs(sx, sy)
    print sum([sum(v) for v in isVisited])

