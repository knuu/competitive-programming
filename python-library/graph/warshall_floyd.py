# cost[i][j] : lengths (weights) from i to j
def warshall_floyd(v):
    """Warshall-Floyd Algorithm: 
       find the lengths of the shortest paths between all pairs of vertices
       ---
       inputs
       1. v: the number of verteices
    """
    for k in range(v):
        for i in range(v):
            for j in range(v):
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])
