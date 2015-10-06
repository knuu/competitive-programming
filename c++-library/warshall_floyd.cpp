#define MAX_V 1000
#define INF 1<<30

// graph by adjacency list

struct Graph {
  int V;
  int Adj[MAX_V][MAX_V];

  Graph(int V) : V(V) {
    for (int i = 0; i < V; i++) {
      std::fill(Adj[i], Adj[i] + V, INF);
      Adj[i][i] = 0;
    }
  }

  void add_edge(int src, int dst, int weight) {
    Adj[src][dst] = weight;
  }

};

struct AllPairsShortestPath {
  Graph g;
  
  AllPairsShortestPath(const Graph &g) : g(g) { }

  void warshall_floyd() {
    for (int k = 0; k < g.V; k++) {
      for (int i = 0; i < g.V; i++) {
	for (int j = 0; j < g.V; j++)
	  g.Adj[i][j] = min(g.Adj[i][j], g.Adj[i][k] + g.Adj[k][j]);
      }
    }
  }

  bool has_negative_loop() {
    for (int i = 0; i < g.V; i++) {
      if (g.Adj[i][i] < 0) return true;
    }
    return false;
  }
};
  

  
  
  
