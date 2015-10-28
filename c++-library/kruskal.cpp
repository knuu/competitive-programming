#define INF 1<<30
#define MAX_V 10010

// graph by adjacency list
struct Edge {
  int src, dst, weight;
  Edge(int src, int dst, int weight) :
    src(src), dst(dst), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight > e.weight; // reverse
  }
};

struct Graph {
  int V;
  std::vector<Edge> E;

  Graph(int V) : V(V) { }

  void add_edge(int src, int dst, int weight) {
    E.push_back(Edge(src, dst, weight));
  }
};


struct DisjointSet {
  int parent[MAX_V];
  int rank[MAX_V];

  DisjointSet(int N) {
    for (int i = 0; i < N; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return ;

    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
      
};

struct MinimumSpanningTree {
  Graph g;
  std::vector<Edge> msp;
  int mincost;

  MinimumSpanningTree(const Graph &g) : g(g) { }

  int find_mincost() {
    mincost = 0;
    std::sort(g.E.begin(), g.E.end());

    DisjointSet uf(g.V);

    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {
      assert(i < (int)g.E.size());
      Edge e = g.E[i];
      if (!uf.same(e.src, e.dst)) {
	uf.unite(e.src, e.dst);
	mincost += e.weight;
	edge_count--;
      }
    }
    return mincost;
  }
};