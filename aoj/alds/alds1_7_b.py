class Node:
    def __init__(self):
        self.parent = -1
        self.sibling = -1


def dfs(v, d=0):
    G[v].depth, G[v].height = d, 0
    if G[v].left != -1:
        G[v].height = max(G[v].height, dfs(G[v].left, d+1) + 1)
    if G[v].right != -1:
        G[v].height = max(G[v].height, dfs(G[v].right, d+1) + 1)
    return G[v].height

N = int(input())
G = [Node() for _ in range(N)]
for _ in range(N):
    idx, *children = [int(x) for x in input().split()]
    G[idx].left, G[idx].right = children
    if G[idx].left != -1 and G[idx].right != -1:
        G[G[idx].left].sibling, G[G[idx].right].sibling = G[idx].right, G[idx].left
    if G[idx].left != -1 or G[idx].right != -1:
        G[idx].type = 'internal node'
    else:
        G[idx].type = 'leaf'
    for child in children:
        if child != -1:
            G[child].parent = idx
root = [i for i, x in enumerate(G) if x.parent == -1][0]
G[root].type = 'root'
dfs(root)
for i, node in enumerate(G):
    print('node {}: parent = {}, sibling = {}, degree = {}, depth = {}, height = {}, {}'.format(i, node.parent, node.sibling, (node.left != -1) + (node.right != -1), node.depth, node.height, node.type))
