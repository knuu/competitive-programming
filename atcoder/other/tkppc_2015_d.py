from heapq import heappop, heappush
range = xrange; input = raw_input
N, R, C = map(int, input().split())
board = [[input() for _ in range(R)] for _ in range(N)]
edge = [[] for _ in range(N*R*C)]

def enc(f, r, c):
    return f*R*C + r*C + c

for f, floor in enumerate(board):
    for r, row in enumerate(floor):
        for c, column in enumerate(row):
            if column == 'H':
                edge[enc(f, r, c)].append((enc(f+1, r, c), int(board[f+1][r][c])))
            else:
                if r < R-1:
                    next_node = enc(f, r+1, c)
                    if board[f][r+1][c] == 'H':
                        cost = 0
                    else:
                        cost = int(board[f][r+1][c])
                    edge[enc(f, r, c)].append((next_node, cost))
                if c < C-1:
                    next_node = enc(f, r, c+1)
                    if board[f][r][c+1] == 'H':
                        cost = 0
                    else:
                        cost = int(board[f][r][c+1])
                    edge[enc(f, r, c)].append((next_node, cost))

#for r in edge: print(r)
dist = [float('inf')] * (N*R*C)
dist[0] = 0
que = list()
heappush(que, (0, 0))

while len(que) > 0:
    d, fr = heappop(que)
    if dist[fr] < d: continue
    for to, cost in edge[fr]:
        if dist[fr] + cost < dist[to]:
            dist[to] = dist[fr] + cost
            heappush(que, (dist[to], to))
print(dist[N*R*C-1])
#print(dist)
