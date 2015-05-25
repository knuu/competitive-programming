# unproved
def minSpanningTree(V, E):
    """ find minimum spanning tree
       need Union-Find Tree
       V: the number of vertexes
       E: edges (v1, v2, cost)
    """
    edges = sorted([(cost, f, t) for v1, v2, cost in E])
    mincost = 0
    uf = UnionFindTree(V)
    for cost, v1, v2 in edge:
        if uf.same(v1, v2) == False:
            mincost += cost
            uf.unite(v1, v2)
    return mincost
    
    
