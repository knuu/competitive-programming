#define INF 1<<30
#define MAX_V 1000000

// graph by adjacency list
struct Edge {
  int dst, weight;
  Edge(int dst, int weight) :
    dst(dst), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight > e.weight;
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

struct ShortestPath {
  const Graph g;
  int start;
  int dist[MAX_V], prev[MAX_V];

  ShortestPath(const Graph g, int start) :
    g(g), start(start) { }

  void bellman_ford() {
    std::fill(dist, dist + g.V, INF);
    dist[start] = 0;
    prev[start] = -1;
    while (true) {
      bool update = false;
      for (int i = 0; i < g.V; i++) {
	for (Edge e : g.E[i]) {
	  if (dist[i] != INF && dist[i] + e.weight < dist[e.dst]) {
	    dist[e.dst] = dist[i] + e.weight;
	    prev[e.dst] = i;
	    update = true;
	  }
	}
      }
      if (!update) break;
    }
  }

  std::vector<int> build_path(int goal) {
    std::vector<int> path;
    for (int v = goal; v != -1; v = prev[v]) {
      path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
  }

  bool find_negative_loop() {
    fill(dist, dist + g.V, 0);

    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) {
	for (Edge e : g.E[j]) {
	  if (dist[j] != INF && dist[j] + e.weight < dist[e.dst]) {
	    dist[e.dst] = dist[j] + e.weight;
	    if (i == g.V - 1) return true;
	  }
	}
      }
    }
    return false;
  }
};
