#define INF 1<<30
#define MAX_V 1000000

// graph by adjacency list
struct Edge {
  int dst, weight;
  Edge(int dst, int weight) :
    dst(dst), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight > e.weight; // reverse
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

struct MinimumSpanningTree {
  Graph g;
  std::vector<Node> mst;
  int mincost;

  MinimumSpanningTree(const Graph &g) : g(g) { }

  int find_mincost() {
    mincost = 0;

    bool used[MAX_V];
    std::fill(used, used + g.V, false);

    std::priority_queue<Node> que;
    que.push(Node(0, 0));

    while (!que.empty()) {
      Node n = que.top(); que.pop();
      int v = n.v, cost = n.dist;
      if (used[v]) continue;
      mst.push_back(n);
      used[v] = true;
      mincost += cost;
      for (Edge e : g.E[v]) {
	if (!used[e.dst]) que.push(Node(e.dst, e.weight));
      }
    }
    return mincost;
  }
};
