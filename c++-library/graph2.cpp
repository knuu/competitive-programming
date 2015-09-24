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

  
  
  
