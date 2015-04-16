def warshall_floyd(cost, v):
    """Warshall-Floyd: 全点対最短路問題
       cost[from][to]: fromからtoまでの最短路長
       v: 頂点数
    """
    for k in range(v):
        for i in range(v):
            for j in range(v):
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])
    return cost
