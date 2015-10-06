#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#define INF 1<<30
#define MAX_V 10010

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
  
int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;
  Graph g(V);
  REP(i, E) {
    int src, dst, weight;
    cin >> src >> dst >> weight;
    g.add_edge(src, dst, weight);
    g.add_edge(dst, src, weight);
  }

  MinimumSpanningTree mst(g);
  cout << mst.find_mincost() << endl;
  return 0;
}
