class Node:
    def __init__(self):
        self.parent = -1


def dfs(v, d=0):
    G[v].depth = d
    for child in G[v].children:
        dfs(child, d+1)


N = int(input())
G = [Node() for _ in range(N)]
for _ in range(N):
    idx, k, *children = [int(x) for x in input().split()]
    G[idx].children = children
    if k:
        G[idx].type = 'internal node'
    else:
        G[idx].type = 'leaf'
    for child in children:
        G[child].parent = idx
root = [i for i, x in enumerate(G) if x.parent == -1][0]
G[root].type = 'root'
dfs(root)
for i, node in enumerate(G):
    print('node {}: parent = {}, depth = {}, {}, [{}]'.format(i, node.parent, node.depth, node.type, ', '.join(map(str, node.children))))
