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

struct Node {
  int v, dist;
  Node(int v, int dist) :
    v(v), dist(dist) { };
  bool operator < (const Node &n) const {
    return dist > n.dist; // reverse
  }
};

struct ShortestPath {
  const Graph g;
  int start;
  int dist[MAX_V], prev[MAX_V];

  ShortestPath(const Graph g, int start) :
    g(g), start(start) { }

  void dijkstra() {
    std::priority_queue<Node> que;
    std::fill(dist, dist + g.V, INF);
    dist[start] = 0;
    que.push(Node(start, 0));
    prev[0] = -1;

    while (!que.empty()) {
      Node n = que.top(); que.pop();
      int v = n.v, cost = n.dist;
      if (dist[v] < cost) continue;
      for (Edge e : g.E[v]) {
	if (dist[v] + e.weight < dist[e.dst]) {
	  dist[e.dst] = dist[v] + e.weight;
	  prev[e.dst] = v;
	  que.push(Node(e.dst, dist[e.dst]));
	}
      }
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
};

  
