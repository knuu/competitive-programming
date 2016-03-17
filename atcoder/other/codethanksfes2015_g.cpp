#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

#define MAX_V 40010

// graph by adjacency list
struct Edge {
  int dst, color; ll weight;
  Edge(int dst, int color, ll weight) :
    dst(dst), color(color), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight < e.weight;
  }
};

struct Graph {
  int V;
  std::vector<Edge> E[MAX_V];
  Graph(int V) : V(V) { }

  void add_edge(int src, int dst, int color, ll weight) {
    E[src].push_back(Edge(dst, color, weight));
  }
};

struct Node {
  int v, color; ll dist;
  Node(int v, int color, ll dist) :
    v(v), color(color), dist(dist) { };
  bool operator < (const Node &n) const {
    return dist > n.dist; // reverse
  }
};

map<int, ll> dist[40010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  Graph g(N);
  REP(i, M) {
    int a, b, c, t; cin >> a >> b >> c >> t; a--, b--;
    g.add_edge(a, b, c, t);
    g.add_edge(b, a, c, t);    
  }

  dist[0][1] = 0;
  priority_queue<Node> pque;
  pque.push(Node(0, 1, 0));

  while (not pque.empty()) {
    Node node = pque.top(); pque.pop();
    int v = node.v, c = node.color; ll d = node.dist;
    if (dist[v].find(c) != dist[v].end() && dist[v][c] < d) continue;
    if (v == N-1) {
      cout << dist[v][c] << endl;
      return 0;
    }
    for (Edge e : g.E[v]) {
      int n_v = e.dst, n_c = e.color; ll n_w = e.weight;
      if (dist[n_v].find(n_c) == dist[n_v].end() || dist[n_v][n_c] > dist[v][c] + n_w + abs(c - n_c)) {
	dist[n_v][n_c] = dist[v][c] + n_w + abs(c - n_c);
	pque.push(Node(n_v, n_c, dist[n_v][n_c]));
      }
    }
  }
  
  return 0;
}
