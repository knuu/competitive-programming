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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

#define INF 1<<25
#define MAX_V 100010

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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  Graph g(N);
  REP(i, N) {
    int p;
    cin >> p;
    if (p) {
      g.add_edge(i, i+p, 0);
    } else {
      FOR(j, 1, 7) g.add_edge(i, i+j, 1);
    }
  }
  ShortestPath sp(g, 0);
  sp.dijkstra();
  cout << sp.dist[N-1] << endl;
  return 0;
}
