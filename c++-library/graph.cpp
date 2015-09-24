#define INF 1<<30
#define MAX_V 1000000

// graph by adjacency list
struct Edge {
  int dst, weight;
  Edge(int dst, int weight) :
    dst(dst), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight < e.weight;
  }
};

struct Graph {
  int V;
  std::vector<Edge> E[MAX_V];

  Graph(int V) : V(V) { }

  void add_edge(int src, int dst, int weight) {
    E[src].push_back(Edge(dst, weight));
  }
};
